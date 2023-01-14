import React, { useState } from 'react'

import './TabPanel.css'
import TabPanelCard from './TabPanelCard';

function TabPanel() {

    const [showtab, setShowtab] = useState(1);

    const handletab = (e) => {
        setShowtab(e);
    }

    return (
        <>
            <>

                <div className="container">
                    <div className="d-flex flex-wrap justify-content-around mx-auto my-2">
                        <h4 className={showtab === 1 ? "active navtabItem" : "navtabItem"} onClick={() => handletab(1)}>PHP</h4>
                        <h4 className={showtab === 2 ? "active navtabItem" : "navtabItem"} onClick={() => handletab(2)}>MERN</h4>
                        <h4 className={showtab === 3 ? "active navtabItem" : "navtabItem"} onClick={() => handletab(3)}>DJANGO</h4>
                    </div>
                    <div className="tab-content my-3" id="pills-tabContent">

                        {/* start tab 1*/}
                        <div className={showtab === 1 ? "tab-pane fade show active p-4" : "tab-pane fade show p-4"}>

                            <div className="container">
                                <div className="row">
                                    <div className="col-lg-4 col-md-6 col-sm-12">
                                        <TabPanelCard title='Uncovercampus' subTitle='one stop solution for all needs of college students' code='https://github.com/anuragkmr45/UC_old.git' />
                                    </div>
                                    <div className="col-lg-4 col-md-6 col-sm-12">
                                        <TabPanelCard title='NFT Market' subTitle='The website where you can buy and sell your NFTs' code='https://github.com/anuragkmr45/NFT_Market.git' />
                                    </div>
                                    <div className="col-lg-4 col-md-6 col-sm-12">
                                        <TabPanelCard title='Yummy' subTitle='this is a restaurant website template' code='https://github.com/anuragkmr45/Yummy.git' />
                                    </div>
                                </div>
                            </div>

                        </div>
                        {/* close tab 1*/}


                        {/* start tab 2*/}
                        <div className={showtab === 2 ? "tab-pane fade show active" : "tab-pane fade"} >
                            <div className="container">
                                <div className="row">
                                    <div className="col-lg-4 col-md-6 col-sm-12">
                                        <TabPanelCard title='Uncovercampus' subTitle='one stop solution for all needs of college students' code='https://github.com/anuragkmr45/UC_old.git' />
                                    </div>
                                    <div className="col-lg-4 col-md-6 col-sm-12">
                                        <TabPanelCard title='Portfolio Website' subTitle='My portfolio website' code='https://github.com/anuragkmr45/portfolio.git' />
                                    </div>
                                </div>
                            </div>
                        </div>
                        {/* close tab 2*/}


                        {/* start tab 3*/}
                        <div className={showtab === 3 ? "tab-pane fade show active" : "tab-pane fade"} >

                        </div>
                        {/* close tab 3*/}

                    </div>
                </div>

            </>
        </>
    )
}

export default TabPanel
