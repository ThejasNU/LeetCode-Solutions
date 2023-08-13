class FizzBuzz {
private:
    int n;
    int i;
    mutex m;
    condition_variable cv;
public:
    FizzBuzz(int n) {
        this->n = n;
        this->i=1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(i<=n && !((i%3==0) && (i%5!=0))){
                cv.wait(lock);
            }
            if(i<=n){
                printFizz();
                i+=1;
            }
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(i<=n && !((i%3!=0) && (i%5==0))){
                cv.wait(lock);
            }
            if(i<=n){
                printBuzz();
                i+=1;
            }
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(i<=n && !((i%3==0) && (i%5==0))){
                cv.wait(lock);
            }
            if(i<=n){
                printFizzBuzz();
                i+=1;
            }
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(i<=n){
            unique_lock<mutex> lock(m);
            while(i<=n && !((i%3!=0) && (i%5!=0))){
                cv.wait(lock);
            }
            if(i<=n){
                printNumber(i);
                i+=1;
            }
            cv.notify_all();
        }
    }
};