import React, { useEffect, useState } from 'react'
import {  Redirect } from 'react-router-dom'
import { useParams } from 'react-router'
import "../../styles/Demo.css"
import { db , timestamp } from '../../Firebase'


const Demo = ({ authorize }) => {
    const { transfer } = useParams()

    const fromname = transfer
    const [sender, setsender] = useState(null)
    const [message, setmessage] = useState("")
    const [senderaccount, setsenderaccount] = useState(null)
    const [senderamount, setsenderammount] = useState(null)
    const [names, setNames] = useState([])
    const [toname, settoname] = useState("")
    const [money, setmoney] = useState("")
    const fetchfromInfo = () => {
        db.collection("customers").where("name", "==", fromname).get()
            .then((querySnapshot) => {
                querySnapshot.forEach((doc) => {
                    setsender(doc.data().name)
                    setsenderaccount(doc.data().account)
                    setsenderammount(doc.data().amount)


                })
            })
            .catch((error) => {
                console.log("Error getting documents: ", error);
            });

    }

    useEffect(() => {
    
        fetchfromInfo()
        db.collection("customers").onSnapshot((snapshot) => {
            setNames(snapshot.docs.map(doc => (doc.data().name)))

        })


    }, [])
    setInterval(() => {
        fetchfromInfo()
    }, 1000)
    function submithandler(e) {
        e.preventDefault()

        if (toname !== "" && money !== "") {
            if (sender !== toname) {
                if (money <= senderamount) {

                    db.collection("customers").where("name", "==", fromname).get()
                        .then((querySnapshot) => {
                            querySnapshot.forEach((doc) => {

                                db.collection("customers").doc(doc.id).set({
                                    name: doc.data().name,
                                    email: doc.data().email,
                                    account: doc.data().account,
                                    number: doc.data().number,
                                    amount: parseInt(doc.data().amount) - parseInt(money),
                                })
                            })

                        })
                    db.collection("customers").where("name", "==", toname).get()
                        .then((querySnapshot) => {
                            querySnapshot.forEach((doc) => {
                                db.collection("customers").doc(doc.id).set({
                                    name: doc.data().name,
                                    email: doc.data().email,
                                    account: doc.data().account,
                                    number: doc.data().number,
                                    amount: parseInt(doc.data().amount) + parseInt(money),
                                })

                            })


                        })
                    var today = new Date();
                    var date = today.getDate() + '-' + (today.getMonth() + 1) + "-" + today.getFullYear()
                    var time = today.getHours() + ":" + today.getMinutes() + ":" + today.getSeconds();
                   
                    db.collection("history2").add({
                        from: fromname,
                        to: toname,
                        money: money,
                        time: time,
                        date: date,
                        series: timestamp,
                    })
                        .then(() => {
                            console.log(date, time, timestamp, toname, fromname)

                        })
                        .catch(error => {
                            alert(error.message)
                        })
                    setmoney('')
                    settoname("")
                    setmessage(money + " rs transfered from " + fromname + " to " + toname)
                    



                }
                else {
                    setmoney('')
                    setmessage("amount insufficent")
                }


            }
            else {
                settoname("")
                setmessage("Reciever same as sender")
            }

        }
        else {
            setmessage("")
            alert("gandu sab field bhar ")
        }

    }
    if (!authorize) {
        return <Redirect to="/" />
    }
    else {
        return (
            <div className="demo-class">
                <h1 className="demo-header">AMBNOX EXPRESS TRANSFER</h1>
                <div className="demo-intro">
                    <span id="name">Name :- {sender}</span><br />
                    <span id="account">Account :- {senderaccount}</span><br />
                    <span id="amount">Amount :- {senderamount}</span><br />
                </div>
                <form className="demo-form" onSubmit={submithandler}>
                    <span>Reciever : </span>
                    <select className="customer-list " data-flip="false" data-dropup-auto="false" value={toname} onChange={(e) => {
                        settoname(e.target.value)
                    }}>
                        <option value="">customers:-</option>
                        {names.map(item => {
                            return <option key={item} value={item}>{item}</option>
                        })}

                    </select>


                    <br />
                    <br />
                    <span>Amount : </span>
                    <input type="number" value={money} onChange={(e) => {
                        setmoney(e.target.value)
                    }} />
                    <br />


                    <br />
                    <br />
                    <button className="btnn btn-success" type="submit"  >Submit</button>
                </form>
                <h1 className="demo-message">{message}</h1>
            </div >
        )
    }


}




export default Demo
