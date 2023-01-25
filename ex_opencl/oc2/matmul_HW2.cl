__kernel void matmul_HW2(
    const int N,
    const __global float *A,
    const __global float *B,
    __global float *C
) {

    int tidx = get_global_id(0);
    int tidy = get_global_id(1);
    float Csub = 0.0f;
    for (int k = 0; k < N; ++k) {
        Csub += A[tidx * N + k] * B[tidy + N * k];
    }

    C[tidx * N + tidy] = Csub;
}
