class Solution {
public:
    int findday( string& date, vector<int>& cummsum){
        int  month = stoi( date.substr(0,2));
        int days = stoi(date.substr(3));
        return cummsum[month - 1] + days;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> cummsum(13,0);
        cummsum[1] = 31;
        for(int  i = 2;i < 13; i++){
            cummsum[i] = cummsum[i - 1] + month[i - 1];
        }
        int  arrAlice = findday(arriveAlice, cummsum);
        int  leaAlice = findday(leaveAlice, cummsum);
        int  arrBob = findday(arriveBob, cummsum);
        int  leaBob = findday(leaveBob, cummsum);
        int overlap = min(leaAlice,leaBob) - max(arrAlice, arrBob) + 1;
        return overlap < 0 ? 0 : overlap;
    }
};
