#include <iostream>
using namespace std;

class NPC {
    int *nums;

    public:
    NPC(int num, int num2) {
        nums = new int[2];
        nums[0] = num;
        nums[1] = num2;
        cout << nums[0] << " " << nums[1] << endl;
    }

    NPC(const NPC &otherChar) {
        nums = new int[2];
        nums[0] = otherChar.nums[0];
        nums[1] = otherChar.nums[1];
        cout << nums[0] << " " << nums[1] << endl;
    }
};

int main() {
    NPC one(1, 2);
    NPC copyOfOne(one);
}