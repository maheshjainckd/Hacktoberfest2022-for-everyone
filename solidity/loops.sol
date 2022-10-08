// SPDX-License-Identifier: UNLICENSED

pragma solidity >=0.4.0 <0.9.0;

contract d1{
    uint[5] public a=[1,2,3,4,5];
    uint public sum;

    function loop() public{
        uint count;
        while(count<a.length){
            sum+=a[count];
            count++;
        }
    }

    function l2()public{
        for(uint i=0;i<a.length;i++){
            sum+=a[i];
        }
    }
    function l3() public{
        uint i;
        do{
            sum += a[i];
            i++;
        }while(i<a.length);
    }
}