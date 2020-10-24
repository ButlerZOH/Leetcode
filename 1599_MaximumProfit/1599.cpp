class Solution {
public
    int minOperationsMaxProfit(vectorint& customers, int boardingCost, int runningCost) {
        if (boardingCost  4  runningCost){
            return -1;
        }
        if(customers.size() == 0){
            return 0;
        }
        int people = 0,time =1,money=-1,total=0,res = 0;
        for (int i = 0; i  customers.size(); i++) {
            people+=customers[i];
            if (people=4){
                total +=4;
                people-=4;
            } else{
                total +=people;
                people-=people;
            }
            if(money(totalboardingCost - timerunningCost)){
                money=totalboardingCost - timerunningCost;
                res = time;
            }
            time++;
        }
        while (people0){
            if (people=4){
                total +=4;
                people-=4;

            } else{
                total +=people;
                people-=people;
            }
            if(money(totalboardingCost - timerunningCost)){
                money=totalboardingCost - timerunningCost;
                res = time;
            }
            time++;
        }
        return res;
    }
};