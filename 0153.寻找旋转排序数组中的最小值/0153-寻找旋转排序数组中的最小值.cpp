class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        while(start+1<end) //�ж�����Ҳ����д��start<end,����ν������ϰ�ߣ�ֻҪ�������Դ������
        {
            int mid=(start+end)>>1;
            if(nums[mid]<nums[end])
            {
                end=mid;
            }
            else if(nums[mid]>nums[end])
            {
                start=mid;
            }
        }
        return min(nums[start],nums[end]);//���𰸶�λ�����������֣�С���Ǹ���Ϊ��
    }
};