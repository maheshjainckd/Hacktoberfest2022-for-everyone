import React, { useState } from 'react'

import './TabPanel.css'

import { FaHtml5, FaCss3Alt, FaBootstrap, FaReact, FaNpm, FaPython, FaJava, FaNodeJs, FaPhp, FaSchool, FaUserGraduate } from "react-icons/fa";
import { SiJavascript, SiMysql, SiMongodb, SiCanva } from "react-icons/si";
import { DiGit, DiDjango } from "react-icons/di";

function TabPanel() {

    const [showtab, setShowtab] = useState(1);

    const handletab = (e) => {
        setShowtab(e);
    }

    return (
        <>
            <>
                <section>
                    <div className="container">
                        <div className="d-flex flex-wrap justify-content-between mx-auto my-2" style={{ backgroundColor: "#66727d94", maxWidth: '55rem', borderRadius: '5rem', backdropFilter: 'blur(60%)' }}>
                            <h4 className={showtab === 1 ? "active navtabItem" : "navtabItem"} onClick={() => handletab(1)}>My Skills</h4>
                            <h4 className={showtab === 2 ? "active navtabItem" : "navtabItem"} onClick={() => handletab(2)}>Education</h4>
                            <h4 className={showtab === 3 ? "active navtabItem" : "navtabItem"} onClick={() => handletab(3)}>EXPERIENCE</h4>
                            <h4 className={showtab === 4 ? "active navtabItem" : "navtabItem"} onClick={() => handletab(4)}>ADDITIONAL SKILLS</h4>
                        </div>
                        <div className="tab-content my-3" id="pills-tabContent">

                            {/* start tab 1*/}
                            <div className={showtab === 1 ? "tab-pane fade show active p-4" : "tab-pane fade show p-4"} style={{ backgroundColor: 'rgba(102, 114, 125, 0.6)', borderRadius: '5rem' }} >

                                <div>
                                    <div className='d-flex flex-wrap justify-content-around'>
                                        <div className="my-3">
                                            <div className="card-body skillCard">
                                                <h5 className="card-title">MARKUP / STYLING <br /> LANGUAGE</h5>
                                                <div className="d-flex justify-content-around my-2 py-2">
                                                    <div>
                                                        <FaHtml5 color='red' fontSize='2rem' />
                                                        <h5>HTML</h5>
                                                    </div>
                                                    <div>
                                                        <FaCss3Alt color='blue' fontSize='2rem' />
                                                        <h5>CSS</h5>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                        <div className="my-3">
                                            <div className="card-body skillCard">
                                                <h5 className="card-title">CSS  <br /> FRAMEWORK</h5>
                                                <div className="my-2 py-2">
                                                    <div>
                                                        <FaBootstrap color='purple' fontSize='2rem' />
                                                        <h5>BOOTSTRAP</h5>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                        <div className="my-3">
                                            <div className="card-body skillCard">
                                                <h5 className="card-title">GRAPHIC DEISGN  <br /> TOOLS</h5>
                                                <div className="my-2 py-2">
                                                    <div>
                                                        <SiCanva fontSize='2rem' />
                                                        <h5>CANVA</h5>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                        <div className="my-3">
                                            <div className="card-body skillCard">
                                                <h5 className="card-title"> FRONT-END <br /> LANGUAGE</h5>
                                                <div className="my-2 py-2">
                                                    <div>
                                                        <SiJavascript color='yellow' fontSize='2rem' />
                                                        <h5>JAVA SCRIPT</h5>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                    </div>

                                    <div className='d-flex flex-wrap justify-content-around'>
                                        <div className="my-3">
                                            <div className="card-body skillCard">
                                                <h5 className="card-title">PROGRAMMING <br /> LANGUAGE </h5>
                                                <div className="d-flex justify-content-around my-2 py-2">
                                                    <div>
                                                        <FaJava color='orange' fontSize='2rem' />
                                                        <h5>JAVA</h5>
                                                    </div>
                                                    <div>
                                                        <FaPython fontSize='2rem' />
                                                        <h5>PYTHON</h5>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                        <div className="my-3">
                                            <div className="card-body skillCard">
                                                <h5 className="card-title">CSS  <br /> FRAMEWORK</h5>
                                                <div className="my-2 py-2">
                                                    <div>
                                                        <FaReact color='blue' fontSize='2rem' />
                                                        <h5>REACT JS</h5>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                        <div className="my-3">
                                            <div className="card-body skillCard">
                                                <h5 className="card-title">DATABASE <br /> MANAGEMENT</h5>
                                                <div className="d-flex justify-content-between my-2 py-2">
                                                    <div className='mx-3'>
                                                        <SiMysql color='blue' fontSize='2rem' />
                                                        <h5>MYSQL</h5>
                                                    </div>
                                                    {/* <div>
                                                        <SiSqlite fontSize='2rem' />
                                                        <h5>SQLITE</h5>
                                                    </div> */}
                                                    <div>
                                                        <SiMongodb color='green' fontSize='2rem' />
                                                        <h5>MONGODB <br /> (NO SQL)</h5>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                        <div className="my-3">
                                            <div className="card-body skillCard">
                                                <h5 className="card-title"> VERSION <br /> CONTROL</h5>
                                                <div className="my-2 py-2">
                                                    <div>
                                                        <DiGit fontSize='2rem' />
                                                        <h5>GIT</h5>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                    </div>


                                    <div className='d-flex flex-wrap justify-content-around'>
                                        <div className="my-3">
                                            <div className="card-body skillCard">
                                                <h5 className="card-title">BACKEND  <br /> FRAMEWORK </h5>
                                                <div className="d-flex justify-content-around my-2 py-2">
                                                    <div>
                                                        <FaNodeJs fontSize='2rem' />
                                                        <h5>NODE JS <br /> (JAVASCRIPT)</h5>
                                                    </div>
                                                    <div>
                                                        <DiDjango fontSize='2rem' />
                                                        <h5>DJANGO <br /> (PYTHON)</h5>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                        <div className="my-3">
                                            <div className="card-body skillCard">
                                                <h5 className="card-title">PACKAGE <br /> MANAGER</h5>
                                                <div className="d-flex justify-content-around my-2 py-2">
                                                    <div className=''>
                                                        <FaNpm fontSize='2rem' />
                                                        <h5>npm</h5>
                                                    </div>
                                                    <div>
                                                        <FaPython fontSize='2rem' />
                                                        <h5>pip</h5>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>

                                        <div className="my-3">
                                            <div className="card-body skillCard">
                                                <h5 className="card-title">GUI <br /> TOOLKIY</h5>
                                                <div className="my-2 py-2">
                                                    <div>
                                                        <FaPython fontSize='2rem' />
                                                        <h5>TKINTER <br />(PYTHON)</h5>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>

                                        <div className="my-3">
                                            <div className="card-body skillCard">
                                                <h5 className="card-title"> BACKEND <br /> LANGUAGE</h5>
                                                <div className="d-flex justify-content-around my-2 py-2">
                                                    <div>
                                                        <FaPhp fontSize='2rem' />
                                                        <h5>PHP</h5>
                                                    </div>
                                                    <div>
                                                        <FaNodeJs fontSize='2rem' />
                                                        <h5>JAVASCRIPT <br />   (NODE JS) </h5>
                                                    </div>
                                                    <div>
                                                        <DiDjango fontSize='2rem' />
                                                        <h5>PYTHON <br /> (DJNAGO) </h5>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>

                            </div>
                            {/* close tab 1*/}


                            {/* start tab 2*/}
                            <div className={showtab === 2 ? "tab-pane fade show active" : "tab-pane fade"} >
                                <div className="container">
                                    <div className="row">
                                        <div className="col-lg-6 col-md-6 col-sm-12">
                                            <div style={{ backgroundColor: 'rgba(102, 114, 125, 0.6)', borderRadius: '5rem' }}>
                                                <div className="h-100 p-5 rounded">
                                                    <h3><FaUserGraduate fontSize='5rem' /> <br /><b>2021 - Percuing</b></h3>
                                                    <h2><b>UNDER-GRADUATION <br />(B.Tech)</b></h2>
                                                    {/* <h4>Percentage - 88%</h4> */}
                                                    <h3>Institute of Technical Education and Research, SOA</h3>
                                                    {/* <ul>
                                                        <li>Had exemplary academic track record with multiple academic excellence award</li>
                                                        <li>Represented school on multiple platforms including on national level.</li>
                                                    </ul> */}
                                                </div>
                                            </div>
                                        </div>
                                        <div className="col-lg-6 col-md-6 col-sm-12">
                                            <div style={{ backgroundColor: 'rgba(102, 114, 125, 0.6)', borderRadius: '5rem' }}>
                                                <div className="h-100 p-5 rounded">
                                                    <h3><FaSchool fontSize='5rem' /> <br /><b>2021</b></h3>
                                                    <h1><b>Class - 12</b></h1>
                                                    <h4>Percentage - 88%</h4>
                                                    <h3>Kendriya Vidhalaya, Noida</h3>
                                                    <ul>
                                                        <li>Had exemplary academic track record with multiple academic excellence award</li>
                                                        <li>Represented school on multiple platforms including on national level.</li>
                                                    </ul>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            {/* close tab 2*/}


                            {/* start tab 3*/}
                            <div className={showtab === 3 ? "tab-pane fade show active" : "tab-pane fade"} >

                                <div className="container">
                                    <div className='p-lg-5 p-2' style={{ backgroundColor: 'rgba(102, 114, 125, 0.6)', borderRadius: '5rem' }}>
                                        <div className="text-center">
                                            <h4>January 2022 - Present </h4>
                                            <h2 style={{ color: 'rgb(203, 178, 106)' }}>Chief Technology Officer (CTO)</h2>
                                            <h5>at <b> uncovercampus.com</b></h5>
                                            <h5>FULL STACK DEVELOPMENT</h5>
                                        </div>
                                        <div className='container mt-4'>
                                            <ul className=''>
                                                <li>
                                                    Lorem ipsum dolor sit amet consectetur adipisicing elit. Ipsam quaerat sed, laudantium modi repudiandae, aliquam quae in corrupti omnis minima laboriosam optio voluptatum labore reiciendis sapiente perferendis nostrum? Ipsam, expedita!
                                                </li>
                                                <li>
                                                    Lorem, ipsum dolor sit amet consectetur adipisicing elit. Vero animi architecto impedit incidunt optio vitae perspiciatis distinctio culpa sunt minus!
                                                </li>
                                                <li>
                                                    Lorem ipsum dolor sit amet consectetur adipisicing elit. Ipsam quaerat sed, laudantium modi repudiandae, aliquam quae in corrupti omnis minima laboriosam optio volperferendis nostrum? Ipsam, expedita!
                                                </li>
                                                <li>
                                                    Lorem, ipsum dolor sit amet consectetur adipisicing elit. Vero animi architecto impedit incidunt optio vitae perspiciatis distinctio culpa sunt minus!
                                                </li>
                                            </ul>
                                        </div>
                                    </div>
                                </div>

                            </div>
                            {/* close tab 3*/}


                            {/* start tab 4*/}
                            <div className={showtab === 4 ? "tab-pane fade show active" : "tab-pane fade"} >

                                <div className="container">
                                    <div className='p-lg-5 p-2' style={{ backgroundColor: 'rgba(102, 114, 125, 0.6)', borderRadius: '5rem' }}>
                                        <div className="text-center">
                                            <h2 style={{ color: 'rgb(203, 178, 106)' }}>SOFT SKILLS</h2>
                                        </div>
                                        <div className='container mt-4'>
                                            <div>
                                                <h3>Communication & Interpersonal skills</h3>
                                                <p>Have the ability to successfully express the desired message while keeping the listener engaged.</p>
                                            </div>
                                            <div>
                                                <h3>Public speaking skills</h3>
                                                <p>Have substantial public speaking experience in the form of event hosting and presenting presentations in front of big groups. Participated in several debate and MUN competitions, which aided in the development of these talents.</p>
                                            </div>
                                            <div>
                                                <h3>Leadership & Management skills</h3>
                                                <p>Skilled in organising others to achieve a common objective and motivating the team to achieve the desired result. Can organise and communicate properly in order to help a team or project</p>
                                            </div>
                                            <div>
                                                <h3>Quick & Visual Learner</h3>
                                                <p>I am a strong visual learner who is driven to tackle challenges and find an efficient solution rapidly</p>
                                            </div>
                                            <div>
                                                <h3>Effective Problem Solver</h3>
                                                <p>I have the capability to solve problems and determining the cause of the problem. Identifying, prioritizing, and selecting alternatives for a solution; and implementing a solution.</p>
                                            </div>
                                        </div>
                                    </div>
                                </div>

                            </div>
                            {/* close tab 4*/}


                        </div>
                    </div>
                </section>
            </>
        </>
    )
}

export default TabPanel
