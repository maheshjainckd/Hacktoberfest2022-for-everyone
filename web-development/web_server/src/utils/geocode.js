const request = require("postman-request");
require("dotenv").config();

const geocode = (address, callback) => {
  const geocodeURL = `https://api.mapbox.com/geocoding/v5/mapbox.places/${encodeURIComponent(
    address
  )}.json?access_token=pk.eyJ1IjoiYmlrYXNrcjU3IiwiYSI6ImNsNnV0MWs2bjFvMGQzZG1tbXJ2ZnIweXEifQ.LNhfoIzXAhBa3yY5QrPYcA&limit=1`;
  // )}.json?access_token=${process.env.accessKey_mapBox}&limit=1`;

  request({ url: geocodeURL, json: true }, (error, response) => {
    if (error) {
      callback("Unable to connect to location services :/", undefined);
    } else if (response.body.features.length === 0) {
      callback("Unable to find location. Try another search", undefined);
    } else {
      callback(undefined, {
        latitude: response.body.features[0].center[1],
        longitude: response.body.features[0].center[0],
        location: response.body.features[0].place_name,
      });
    }
  });
};

module.exports = geocode;
