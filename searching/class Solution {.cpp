class Solution {
public:
    int maxArea(vector<int>& v) {
        int lptr = 0,rptr = v.size() - 1;
        int width = v.size()-1;
        int len = v[0];
        int area = 0;
        while(lptr<rptr)
        {
            if(v[lptr]<v[rptr])
            {
                lptr++;
                width--;
            }
            else
            {
                rptr--;
                width--;
            }
            len = min(v[lptr],v[rptr]);
            area = max(area,len*width);
        }
        return area;
    }
};