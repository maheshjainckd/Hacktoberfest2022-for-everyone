// 75. Sort Colors(leetCode)
//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//You must solve this problem without using the library's sort function.

function colors(nums){
    let right=0,left=nums.length-1,i=0;
    while(i<=left){
        if(nums[i]===0) swap(nums,i++,right++)
        else if(nums[i]===2) swap(nums,i,left--)
        else i++ 
    }
    return nums
}

var swap = function(nums,start,end){
    let temp = nums[start];
    nums[start] = nums[end]
    nums[end] = temp
}

let nums= [0,2,1,1,2,0]
let res = colors(nums);
console.log(res);
