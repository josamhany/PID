// C++ code
//
class PIDController {
private:
    double Kp, Ki, Kd;
    double setpoint, input, output;
    double prevError, integral;
    unsigned long lastTime;

public:
    PIDController(double p, double i, double d) : Kp(p), Ki(i), Kd(d), prevError(0), integral(0), lastTime(millis()) {}

    void setSetpoint(double sp) {
        setpoint = sp;
    }

    double compute(double inputVal) {
        input = inputVal;
        unsigned long now = millis();
        double timeChange = (double)(now - lastTime);

        double error = setpoint - input;

       
        double Pout = Kp * error;

        
        integral += error * timeChange;
        double Iout = Ki * integral;

        
        double derivative = (error - prevError) / timeChange;
        double Dout = Kd * derivative;

        
        output = Pout + Iout + Dout;

       
        prevError = error;
        lastTime = now;

        return constrain(output, 0, 255);
    }
};