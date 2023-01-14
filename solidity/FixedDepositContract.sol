pragma solidity ^0.5.1;

contract FD_Contract{
    //Who can withdraw and how much and when
    address payable public beneficiary;
    uint256 public releaseTime;

    constructor(address payable _beneficiary, uint256 _releaseTime) public payable{
        require(_releaseTime>block.timestamp);
        beneficiary = _beneficiary;
        releaseTime = _releaseTime;
    }

    function release() public {
        require(block.timestamp>=releaseTime);
        address(beneficiary).transfer(address(this).balance);
        //First explicit coversion of beneficiary to address type
        //.transfer is available by default when we add "payable" keyword
        //address(this) refers to the address of the smart contract
        // .balance is a special function that tells gives the ether held in the contract

    }

}