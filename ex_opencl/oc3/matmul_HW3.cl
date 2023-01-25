__kernel void matmul_HW3(
    const int M,
    const int N,
    const int K,
    const __global float *A,
    const __global float *B,
    __global float *C
) {


    int tidx = get_global_id(0);
    int tidy = get_global_id(1);
    if (tidx < M && tidy < N) {
        float Csub = 0.0f;
        for (int k = 0; k < K; ++k) {
            Csub += A[tidx * K + k] * B[tidy + N * k];
        }

        C[tidx * N + tidy] = Csub;
    }
}
