class ParkingSystem {
public:
    int slotsLeft[4];
    ParkingSystem(int big, int medium, int small) {
        slotsLeft[1]=big;
        slotsLeft[2]=medium;
        slotsLeft[3]=small;
    }
    
    bool addCar(int carType) {
        if(slotsLeft[carType]>0){
            slotsLeft[carType]-=1;
            return true;
        }
        else return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */