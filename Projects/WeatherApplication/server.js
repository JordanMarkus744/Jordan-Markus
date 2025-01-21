require("dotenv").config();
const express = require("express");
const axios = require("axios");
const path = require("path");
const cors = require("cors"); // Add this line

const app = express();
const PORT = 3000;

// Use CORS middleware to allow requests from the frontend
app.use(
  cors({
    origin: "http://127.0.0.1:5500", // Replace this with the actual origin of your frontend
    methods: ["GET", "POST"], // Add more methods if needed
    allowedHeaders: ["Content-Type", "Authorization"], // Add headers if needed
  })
);
app.get("/api/weather", async (req, res) => {
  const city = req.query.city;
  const apiKey = process.env.WEATHER_API_KEY;
  const apiUrl = `https://api.openweathermap.org/data/2.5/weather?units=imperial&q=${city}&appid=${apiKey}`;

  try {
    const response = await axios.get(apiUrl);
    res.json(response.data);
  } catch (error) {
    res.status(500).json({ error: "Unable to fetch weather data" });
  }
});

app.listen(PORT, () =>
  console.log(`Server running on http://localhost:${PORT}`)
);
