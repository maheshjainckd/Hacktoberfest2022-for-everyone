import React, { useState } from "react"
import {  Redirect , useHistory } from 'react-router-dom'
import "../../styles/Register.css"
import { db } from "../../Firebase"
function Register({ authorize }) {
    const history = useHistory()
    const [name, setname] = useState('')
    const [amount, setamount] = useState('')
    const [email, setemail] = useState('')
    const [number, setnumber] = useState("")



    function setnamehandler(e) {
        setname(e.target.value)
    }
    function setnumberhandler(e) {
        setnumber(e.target.value)

    }


    function setemailhandler(e) {
        setemail(e.target.value)

    }
    function setamountthandler(e) {
        setamount(e.target.value)
    }
    function randomIntFromInterval(min, max) { // min and max included 
        return Math.floor(Math.random() * (max - min + 1) + min)
    }




    function submithandler(e) {
        e.preventDefault()

        if (name !== "" && number !== "" && email !== "" && amount !== "") {
            if (amount > 1000000) {
                alert("Deposite amount should be less than 10 lakhs  ")
                setname("")
                setamount("")
                setemail("")
                setnumber("")
            }
            else {
                var today = new Date();
                var dat = today.getFullYear() + '-' + (today.getMonth() + 1) + '-' + today.getDate();
                db.collection("customers").add({
                    name: name,
                    account: randomIntFromInterval(1000000000, 9999999999),
                    email: email,
                    amount: parseInt(amount),
                    number: parseInt(number),
                    date: dat
                })
                    .then(() => {
                        console.log("HA BHAI HOGYA ADMISSION ")
                        history.push('/home')

                    })
                    .catch(error => {
                        alert(error.message)

                    })
                setname("")
                setamount("")
                setemail("")
                setnumber("")


            }



        }
        else {
            alert("ALL fields are compulsory")
        }




    }
    if (!authorize) {
        return <Redirect to="/" />
    }
    else {
        return (

            <div className="container-fluid formcontainer">
                <h1 className="register-header">REGISTER HERE </h1>
                <form className="form" onSubmit={submithandler} >
                    <div className="row p-0 m-0" >

                        <div className="inputfield">
                            <h3>Name</h3>
                            <input type="text" value={name} onChange={setnamehandler} />
                        </div>
                        <div className="inputfield">
                            <h3>Email</h3>
                            <input type="email" value={email} onChange={setemailhandler} />

                        </div>
                        <div className="  inputfield">
                            <h3>Number</h3>
                            <input type="number" value={number} onChange={setnumberhandler} />
                        </div>

                        <div className="  inputfield">
                            <h3>Amount</h3>
                            <input type="number" value={amount} onChange={setamountthandler} />
                        </div>


                        <div >
                            <button type="submit" className=" button  submit ">SUBMIT</button>
                        </div>
                    </div>

                </form>

            </div>




        )
    }

}



export default Register
