// SPDX-License-Identifier: GPL-3.0

// contract address on goerli -> 0xA5E5812949CB0cdc955eDB4969472A681444B192
pragma solidity >=0.7.0 <0.9.0;

contract Hello{
    string name = "Dikshant rajput";

    function sayHello() public view returns (string memory){
        return string(abi.encodePacked("Hello world ! ", name, " here ",". Contribute your smart contracts to show the power of etehreum community to the world"));
    } 

}