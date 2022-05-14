/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();

        // vector 容器可以直接sort
        sort(nums1.begin(),nums1.end());

        // pair是一个特殊的操作 pair.first pair.second
        vector<pair<int,int>> newnums2;

        // 将 nums2 的值和对应索引push back 数组内
        for(int i=0;i<n;i++){
            newnums2.push_back(pair<int,int>(nums2[i],i));
        }

        // sort 函数可以穿入 sort标志。按 first 进行排序
        sort(newnums2.begin(),newnums2.end(),[](const pair<int,int>& a1,const pair<int,int>& a2){
            return a1.first<=a2.first;
        });

        // 定义返回数组，并且设定初始值为-1，以用来填充
        vector<int> res(n,-1);

        int a=n-1;
        int b=n-1;

        // 先将能赢的放进 res 可以理解为贪心算法
        while(a>=0&&b>=0){
            if(nums1[a]>newnums2[b].first){
                res[newnums2[b].second]=nums1[a];
                a--;
                b--;
            }
            else{
                b--;
            }
        }

        // 然后将赢不了的放进空位置
        if(a!=-1){
            for(int i=0;i<n;i++){
                if(res[i]==-1){
                    res[i]=nums1[a];
                    a--;
                }
            }
        }
        
        return res;
    }
};
// @lc code=end

