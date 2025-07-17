const char INDEX_HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <title>Welcome</title>
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <style>
    body {
      margin: 0;
      padding: 0;
      background: linear-gradient(135deg, #4e54c8, #8f94fb);
      font-family: Arial, sans-serif;
      color: #333;
      display: flex;
      align-items: center;
      justify-content: center;
      min-height: 100vh;
    }
    .card {
      background: #fff;
      padding: 2rem;
      border-radius: 1rem;
      box-shadow: 0 0 20px rgba(0,0,0,0.1);
      max-width: 320px;
      width: 90%;
      text-align: center;
    }
    h1 {
      font-size: 1.5rem;
      margin: 0 0 0.5rem;
      color: #4e54c8;
    }
    p {
      font-size: 1rem;
      margin: 0.5rem 0 1.5rem;
    }
    a.button {
      display: inline-block;
      padding: 0.8rem 1.2rem;
      background: #4e54c8;
      color: #fff;
      text-decoration: none;
      border-radius: 0.5rem;
      font-weight: bold;
      transition: background 0.3s;
    }
    a.button:hover {
      background: #3b41a1;
    }
    .footer {
      font-size: 0.75rem;
      color: #777;
      margin-top: 1.5rem;
    }
  </style>
</head>
<body>
  <div class="card">
    <h1>ESP32 Captive Portal</h1>
    <p>You are now connected to the ESP32 AP.</p>
    <a href="/graph" class="button">Continue</a>
    <div class="footer">&copy; 2025 My ESP32 Device</div>
  </div>
</body>
</html>
)rawliteral";