import React, { useState, useEffect } from 'react'
import "../../styles/Deposite.css"
import { db } from '../../Firebase'
import {Redirect} from "react-router-dom"
function Deposite({ authorize }) {

    const [bankaccount, setbankaccount] = useState([])
    const [operation, setoperation] = useState('')
    const [pesa, setpesa] = useState('')
    const [message, setmessage] = useState('')
    const [selectedaccount, setselectedaccount] = useState('')
    useEffect(() => {
        db.collection("customers").onSnapshot((snapshot) => {
            setbankaccount(snapshot.docs.map(doc => (doc.data().name)))
        })
    }, [])


    function submitHandler(e) {
        e.preventDefault()
        if (operation !== "" && selectedaccount !== '' && pesa !== '') {
            if (operation === "D") {
                db.collection("customers").where("name", "==", selectedaccount).get()
                    .then((querySnapshot) => {
                        querySnapshot.forEach((doc) => {

                            db.collection("customers").doc(doc.id).set({
                                name: doc.data().name,
                                email: doc.data().email,
                                account: doc.data().account,
                                number: doc.data().number,
                                amount: parseInt(doc.data().amount) + parseInt(pesa),

                            })

                            console.log("hogyabhai")
                            console.log(operation, selectedaccount, "deposite")
                            setmessage(pesa + " rs deposited to " + selectedaccount + "'s account")
                            setoperation("")
                            setpesa("")
                            setselectedaccount("")

                        })
                    })
                    .catch((error) => {
                        console.log("Error getting documents: ", error);
                    });


            }
            else {
                db.collection("customers").where("name", "==", selectedaccount).get()
                    .then((querySnapshot) => {
                        querySnapshot.forEach((doc) => {
                            if (doc.data().amount >= pesa) {
                                db.collection("customers").doc(doc.id).set({
                                    name: doc.data().name,
                                    email: doc.data().email,
                                    account: doc.data().account,
                                    number: doc.data().number,
                                    amount: parseInt(doc.data().amount) - parseInt(pesa),

                                })
                                console.log("hogyabhai")
                                console.log(operation, selectedaccount, "withdraw")
                                setmessage(pesa + " rs withdrawn from " + selectedaccount + "'s account")
                                setoperation("")
                                setpesa("")
                                setselectedaccount("")



                            }
                            else {
                                alert("ammount insufficient")
                                setmessage("")
                            }


                        })
                    })
                    .catch((error) => {
                        console.log("Error getting documents: ", error);
                    });

                // 
            }

        }
        else {
            alert("all fields are required")
            setmessage("")
        }

    }

    if (!authorize) {
        return <Redirect to="/" />
    }
    else {
        return (
            <div className="deposite-container">
                <h1>EXPRESS WITHDRAWAL/DEPOSITION</h1>
                <div className="form-container container">
                    <form onSubmit={submitHandler} >
                        <h2>SELECT ACCOUNT </h2>
                        <select className="customer-list-depo " value={selectedaccount} onChange={(e) => { setselectedaccount(e.target.value) }} data-flip="false" data-dropup-auto="false" >
                            <option value="">ACCOUNTS:-</option>

                            {bankaccount.map(item => {
                                return <option key={item} value={item}>{item}</option>
                            })}

                        </select>

                        <h2>Enter amount </h2>
                        <input className="input" value={pesa} onChange={(e) => { setpesa(e.target.value) }} type="number" />

                        <h2>Deposite / Withdraw</h2>

                        <select className="customer-list-depo " value={operation} onChange={(e) => { setoperation(e.target.value) }} data-flip="false" data-dropup-auto="false"  >
                            <option value="">OPRATION:-</option>
                            <option value="D">DEPOSITE</option>
                            <option value="W">WITHDRAW</option>
                        </select><br />
                        <button className="btndw btn-dark" type="submit">SUBMIT</button>
                    </form>
                </div>

                <div className="depo-message">
                    <h1>{message}</h1>
                </div>

            </div>
        )
    }





}

export default Deposite
