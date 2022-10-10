import React, { useEffect, useState } from 'react'
import {  Redirect } from 'react-router-dom'
import { db } from '../../Firebase'
import "../../styles/History.css"
function History({ authorize }) {
    const [history, sethistory] = useState([])

    function randomIntFromInterval(min, max) {
        return Math.floor(Math.random() * (max - min + 1) + min)
    }
    useEffect(() => {
        db.collection('history2').orderBy("series", "desc").limit(17).onSnapshot(snapshot => {
            sethistory(snapshot.docs.map(doc => doc.data()))
        })

    }, [])

    if (!authorize) {
        return <Redirect to="/" />
    }
    else {
        return (
            <div className="history" >
                <h1 className="history-header">TRANSACTION HISTORY</h1>
                <table className="tble ">
                    <tbody>
                        <tr key={randomIntFromInterval(90000000, 1000000000)}>
                            <th>date</th>
                            <th>time</th>
                            <th>from</th>
                            <th>to</th>
                            <th>money</th></tr>
                        
                        {history.map((item) => {

                            return (
                                <tr key={item.time}>
                                    <td>{item.date}</td>
                                    <td>{item.time}</td>
                                    <td>{item.from}</td>
                                    <td>{item.to}</td>
                                    <td>{item.money}</td>

                                </tr>)


                        })}

                    </tbody>
                </table>
            </div>
        )
    }

}

export default History
