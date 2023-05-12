/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let ans=[]
    arr.forEach((ele,idx)=>{
        if(fn(ele,idx)) ans.push(ele)
    })
    return ans
};