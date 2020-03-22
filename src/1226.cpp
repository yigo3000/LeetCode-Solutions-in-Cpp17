class DiningPhilosophers {
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l = philosopher;
        int r = (philosopher + 1) % 5;
        m.lock();
        lock_guard<mutex> lk1(v[l]);
        lock_guard<mutex> lk2(v[r]);
        pickLeftFork();
        pickRightFork();
        m.unlock();
        eat();
        putLeftFork();
        putRightFork();
    }
private:
    mutex m;
    mutex v[5];
};