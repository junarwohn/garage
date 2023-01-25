#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#define MAX_SOURCE_SIZE (0x100000)

int main(void) {
    int i;
    //const int LIST_SIZE = 1024;
    const int LIST_SIZE = 4096;
    int *A = (int*)malloc(sizeof(int)*LIST_SIZE);
    int *B = (int*)malloc(sizeof(int)*LIST_SIZE);
    for(i = 0; i < LIST_SIZE; ++i) {
        A[i] = i;
        B[i] = LIST_SIZE - i;

    }

    FILE *fp;
    char *src_str;
    size_t src_size;

    double start_time, end_time;

    start_time = clock();

    fp = fopen("opencl_kernel.cl", "r");
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


    size_t max_work_group_sz;
    clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(max_work_group_sz), &max_work_group_sz, NULL );
    // clGetDeviceInfo(device_id, CL_KERNEL_WORK_GROUP_SIZE, sizeof(max_work_group_sz), &max_work_group_sz, NULL );
    printf("CL_DEVICE_MAX_WORK_GROUP_SIZE : %ld\n", max_work_group_sz);

    cl_context context = clCreateContext( NULL, 1, &device_id, NULL, NULL, &ret );
    
    cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

    cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE * sizeof(int), NULL, &ret);

    cl_mem b_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE * sizeof(int), NULL, &ret);

    cl_mem c_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, LIST_SIZE * sizeof(int), NULL, &ret);
    
    ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0, LIST_SIZE * sizeof(int), A, 0, NULL, NULL);

    ret = clEnqueueWriteBuffer(command_queue, b_mem_obj, CL_TRUE, 0, LIST_SIZE * sizeof(int), B, 0, NULL, NULL);

    cl_program program = clCreateProgramWithSource(context, 1, (const char **)&src_str, (const size_t *)&src_size, &ret);

    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

    cl_kernel kernel = clCreateKernel(program, "vector_add", &ret);

    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *) &a_mem_obj);
    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *) &b_mem_obj);
    ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *) &c_mem_obj);

    // size_t global_item_size[] = {LIST_SIZE , LIST_SIZE };
    size_t global_item_size = LIST_SIZE;
    // size_t local_item_size[] = {64, 64};
    size_t local_item_size = 128;
    // ret = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, global_item_size, local_item_size, 0, NULL, NULL);
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);
    end_time = clock();

    if (ret != 0)
        printf("ERROR CODE : %d\n", ret);

    int *C = (int*)malloc(sizeof(int)*LIST_SIZE);
    ret = clEnqueueReadBuffer(command_queue, c_mem_obj, CL_TRUE, 0, LIST_SIZE * sizeof(int), C, 0, NULL, NULL);

    for( i = 0; i < LIST_SIZE; ++i ) {
        printf("%d + %d = %d\n", A[i], B[i], C[i]);
    }

    printf("%ld\n", local_item_size);
    printf("Execution time: %lf sec\n", (end_time - start_time) / CLOCKS_PER_SEC);
    ret = clFlush(command_queue);
    ret = clFinish(command_queue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(a_mem_obj);
    ret = clReleaseMemObject(b_mem_obj);
    ret = clReleaseMemObject(c_mem_obj);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);
    free(A);
    free(B);
    free(C);

    return 0;

}
