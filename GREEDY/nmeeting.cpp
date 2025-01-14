    struct meeting {
   int start;
   int end;
   int pos;
};
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    bool static comparator(struct meeting m1,meeting m2){
        if(m1.end<m2.end) return true;
        else if(m1.end>m2.end) return false;
        else if(m1.pos<m2.pos)return true;
        return false;
      }

    int maxMeetings(vector<int>& start, vector<int>& end) {
        struct meeting meet[start.size()];
        for(int i = 0 ; i<start.size();i++){
          meet[i].start = start[i];
          meet[i].end = end[i];
          meet[i].pos = i+1;
        }
        sort(meet,meet+start.size(),comparator);
        int cnt = 1;
        int freeTime = meet[0].end;

        for(int i = 1 ; i<start.size();i++){
          if(meet[i].start>freeTime){
            cnt++;
            freeTime = meet[i].end;
          }
        }
        return cnt;
      }
};
