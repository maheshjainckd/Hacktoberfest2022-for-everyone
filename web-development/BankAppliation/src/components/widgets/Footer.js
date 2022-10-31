import React from 'react'

import "../../styles/Footer.css"

function Footer() {

    return (
        <div className="footer">
            <div className="footer-contianer">
                <div className="row">
                    <div className="col-lg-4 footer-col">
                        <h6>Follow me</h6>
                        <ul>
                            <li className="follow-list" id="linkedin"  ><a href="https://www.linkedin.com/in/himanshu-kumar-amb/"  rel="noreferrer" target="blank"> <i className="fa fa-linkedin "></i>. linked in </a></li>
                            <li className="follow-list" id="instagram" ><a href="https://www.instagram.com/himanshu_kumar_amb/" rel="noreferrer" target="blank"> <i className="fa fa-instagram "></i>. instagram </a></li>
                            <li className="follow-list" id="github"><a href="#"  rel="noreferrer" > <i className="fa fa-github "></i>.github </a></li>
                        </ul>

                    </div>

                    <div className="col-lg-4 footer-col">
                        <h6>contact me </h6>
                        <ul>
                            <li id="mail"> <i className="fa fa-envelope" aria-hidden="true"></i> mail: earthboxer@gmail.com</li>
                            <li id="fiver"><i className="fa fa-wrench "></i> <a id="hte" rel="noreferrer"   href="https://www.fiverr.com/earthboxer?up_rollout=true" target="_blank"><i className="fa fa-fiver "></i> fiver: earthboxer</a></li>
                            <li id="phone"><i className="fa fa-phone "></i> phone :702485234</li>
                        </ul>
                    </div>
                    <div className="col-lg-4 footer-col projects">
                        <h6>projects</h6>
                        <ul>
                            <li><a href="https://himanshu-react-weather-app.netlify.app/" target="_blank" rel="noreferrer"> <i className="fa fa-cloud "></i> Wearther app</a></li>
                            <li><a href="https://himanshu-connect-four-game.netlify.app/" target="_blank" rel="noreferrer"><i className="fa fa-gamepad "></i> connect four game app</a></li>
                            <li><a href="https://himanshu17-2000.github.io/himanshu1/portfolio.html" target="_blank" rel="noreferrer"><i className="fa fa-user "></i> portfolio app</a></li>
                            <li><a href="https://himanshu-fullstack-photogalary.netlify.app/" target="_blank" rel="noreferrer" ><i className="fa fa-picture-o" aria-hidden="true"></i> Full-stack gallery</a></li>
                        </ul>
                    </div>
                </div>

            </div>
        </div>
    )
}

export default Footer



