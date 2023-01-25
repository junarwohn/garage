__kernel void matmul_HW4(
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
        for (int k = 0; k < K; k += 8) {
            if (k < K) {
                Csub += A[tidx * K + k] * B[tidy + N * k];
                Csub += A[tidx * K + k + 1] * B[tidy + N * (k + 1)];
                Csub += A[tidx * K + k + 2] * B[tidy + N * (k + 2)];
                Csub += A[tidx * K + k + 3] * B[tidy + N * (k + 3)];
                Csub += A[tidx * K + k + 4] * B[tidy + N * (k + 4)];
                Csub += A[tidx * K + k + 5] * B[tidy + N * (k + 5)];
                Csub += A[tidx * K + k + 6] * B[tidy + N * (k + 6)];
                Csub += A[tidx * K + k + 7] * B[tidy + N * (k + 7)];
            }
        }

        C[tidx * N + tidy] = Csub;
    }
}
