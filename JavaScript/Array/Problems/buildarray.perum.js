
var buildArray = function(nums) {
    let n=[...nums]
    for(let i=0;i<nums.length;i++){
        
        nums[i]=n[nums[i]]
        // for(let j=0;j<nums.length;j++){
        // nums[j]=nums[nums[j]]
        // } 
    }
    return nums
};


// // 
// // Input: nums = [5,0,1,2,3,4]
// Output: [4,5,0,1,2,3]

// >>>>>>> d3cd315413245e33e12e4f57621aaad4d8b70d9c
console.log(buildArray([5,0,1,2,3,4]))