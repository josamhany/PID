double exponentialSmoothing(double newValue) {
    static double smoothedValue = 0;
    double alpha = 0.1;
    smoothedValue = alpha * newValue + (1 - alpha) * smoothedValue;
    return smoothedValue;
}