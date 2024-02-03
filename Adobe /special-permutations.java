class Solution {
    int mod = (int)1e9+7;
    int[][] t;
    public int specialPerm(int[] nums) {
        int n = nums.length;
        t = new int[n][1<<n];
        for(int[] i : t)Arrays.fill(i,-1);
        return helper(nums,0,0);
    }
    int helper(int[] nums, int i, int mask){
        int n = nums.length;
        if(mask==((1<<n)-1))return 1;
        if(t[i][mask]!=-1)return t[i][mask];
        int count = 0;
        for(int k = 0;k<n;k++){
            boolean vis = ((mask & (1<<k))!=0);
            if(!vis){
               if(mask==0 || nums[i]%nums[k]==0 || nums[k]%nums[i]==0){
                   int newMask = (mask | (1<<k));
                   count = (count%mod + helper(nums,k,newMask)%mod)%mod;
               } 
            }
        }
        return t[i][mask] = count; 
    }
}
