class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        cummsum = [0] * 13
        cummsum[1] = 31
        for i in range(2,13):
            cummsum[i] = cummsum[i - 1] + month[i - 1]
        def findday(date, cummsum):
            month = int(date[:2])
            days  = int(date[3:])
            return cummsum[month - 1] + days
        aa = findday(arriveAlice,cummsum)
        al = findday(leaveAlice,cummsum)
        ba = findday(arriveBob,cummsum)
        bl = findday(leaveBob,cummsum)
        overlap = min(al,bl) - max(aa,ba) + 1
        if overlap < 0:
            return 0
        return overlap
        
