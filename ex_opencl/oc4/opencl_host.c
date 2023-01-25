#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#define MAX_SOURCE_SIZE (0x100000)

int validation(int M, int N, int K, float * a, float* b, float* c) {
    int is_valid = 1;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            float sub = 0;
            for (int k = 0; k < K; ++k) {
                sub += a[i*K + k] * b[j + N*k];
            }
            if (c[i*N + j] != sub) {
                return -1;
            }
        }
    }
    return is_valid;
}

int main(void) {
    int i, j;
    const int LIST_SIZE_M = 2048;
    const int LIST_SIZE_N = 1536;
    const int LIST_SIZE_K = 1024;
    float *A = (float*)malloc(sizeof(float)*LIST_SIZE_M*LIST_SIZE_K);
    float *B = (float*)malloc(sizeof(float)*LIST_SIZE_K*LIST_SIZE_N);
    
    for(i = 0; i < LIST_SIZE_M*LIST_SIZE_K; ++i) {
        A[i] = i % LIST_SIZE_N;
    }
    
    for(i = 0; i < LIST_SIZE_K*LIST_SIZE_N; ++i) {
        B[i] = i % LIST_SIZE_M;
    }

    FILE *fp;
    char *src_str;
    size_t src_size;

    double start_time, end_time;

    start_time = clock();

    fp = fopen("matmul_HW4.cl", "r");
    if (!fp) {
        fprintf(stderr, "Failed to load kernel.\n");
        exit(1);
    }
    src_str = (char*)malloc(MAX_SOURCE_SIZE);
    src_size = fread(src_str, 1, MAX_SOURCE_SIZE, fp);
    fclose( fp );

    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint ret_num_devices;
    cl_uint ret_num_platforms;

    cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);

    ret = clGetDeviceIDs( platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);

    cl_context context = clCreateContext( NULL, 1, &device_id, NULL, NULL, &ret );
    
    cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 0, &ret);



    // cl_mem N_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int), NULL, &ret);
    // cl_mem M_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int), NULL, &ret);
    // cl_mem K_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int), NULL, &ret);

    cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE_M*LIST_SIZE_K * sizeof(float), NULL, &ret);

    cl_mem b_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE_K*LIST_SIZE_N * sizeof(float), NULL, &ret);

    cl_mem c_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, LIST_SIZE_M*LIST_SIZE_N * sizeof(float), NULL, &ret);
    

    
    // ret = clEnqueueWriteBuffer(command_queue, N_mem_obj, CL_TRUE, 0, sizeof(int), &LIST_SIZE_M, 0, NULL, NULL);
    // ret = clEnqueueWriteBuffer(command_queue, M_mem_obj, CL_TRUE, 0, sizeof(int), &LIST_SIZE_N, 0, NULL, NULL);
    // ret = clEnqueueWriteBuffer(command_queue, K_mem_obj, CL_TRUE, 0, sizeof(int), &LIST_SIZE_K, 0, NULL, NULL);

    ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0, LIST_SIZE_M*LIST_SIZE_K * sizeof(float), A, 0, NULL, NULL);

    ret = clEnqueueWriteBuffer(command_queue, b_mem_obj, CL_TRUE, 0, LIST_SIZE_K*LIST_SIZE_N * sizeof(float), B, 0, NULL, NULL);

    cl_program program = clCreateProgramWithSource(context, 1, (const char **)&src_str, (const size_t *)&src_size, &ret);

    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

    cl_kernel kernel = clCreateKernel(program, "matmul_HW4", &ret);

    ret = clSetKernelArg(kernel, 0, sizeof(int), (void *) &LIST_SIZE_M);
    ret = clSetKernelArg(kernel, 1, sizeof(int), (void *) &LIST_SIZE_N);
    ret = clSetKernelArg(kernel, 2, sizeof(int), (void *) &LIST_SIZE_K);
    ret = clSetKernelArg(kernel, 3, sizeof(cl_mem), (void *) &a_mem_obj);
    ret = clSetKernelArg(kernel, 4, sizeof(cl_mem), (void *) &b_mem_obj);
    ret = clSetKernelArg(kernel, 5, sizeof(cl_mem), (void *) &c_mem_obj);
    
    size_t global_item_size[2] = {LIST_SIZE_M, LIST_SIZE_N};
    // size_t global_item_size = LIST_SIZE;
    //size_t local_item_size[2] = {8, 8};
    size_t local_item_size[2] = {32, 32};
    // size_t local_item_size = 64;
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, global_item_size, local_item_size, 0, NULL, NULL);

    end_time = clock();


    float *C = (float*)malloc(sizeof(float)*LIST_SIZE_M*LIST_SIZE_N);

    ret = clEnqueueReadBuffer(command_queue, c_mem_obj, CL_TRUE, 0, LIST_SIZE_M*LIST_SIZE_N * sizeof(float), C, 0, NULL, NULL);

    // for( i = 0; i < 32 * 32; ++i ) {
    //     for (j = 0; j < 32; ++j) {
    //         printf("%lf ", C[i*32 + j]);
    //     }
    //     printf("\n");
    // }
    printf("C[%d] : %lf\n", 1995, C[1995]);
    // C[1995] = 1995;
    printf("Execution time: %lf sec\n", (end_time - start_time) / CLOCKS_PER_SEC);
    if (validation(LIST_SIZE_M, LIST_SIZE_N, LIST_SIZE_K, A, B, C) == -1) {
        printf("result : FAILED\n");
    } else {
        printf("result : PASSED\n");
    }
    printf("%d\n", ret);

    ret = clFlush(command_queue);
    ret = clFinish(command_queue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(a_mem_obj);
    ret = clReleaseMemObject(b_mem_obj);
    ret = clReleaseMemObject(c_mem_obj);
    // ret = clReleaseMemObject(N_mem_obj);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);
    free(A);
    free(B);
    free(C);

    return 0;

}

