#include <WiFi.h>
#include <WebServer.h>

// LED pins
const int led1 = 5;
const int led2 = 18;
const int led3 = 19;

// Web server on port 80
WebServer server(80);

// Access Point credentials
#include <WiFi.h>
#include <WiFi.h>
const char* ssid = "Gaspher-Light";
const char* password = "12345678";  // Must be at least 8 characters

// HTML dashboard with enhanced styling and content
String webpage = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>AN INTELLIGENT LIGHT SYSTEM</title>
  <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;600&display=swap" rel="stylesheet">
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css">
  <style>
    :root {
      --primary: #4361ee;
      --secondary: #3f37c9;
      --accent: #4895ef;
      --dark: #1b263b;
      --light: #f8f9fa;
      --success: #4cc9f0;
      --danger: #f72585;
      --warning: #f8961e;
      --info: #560bad;
    }
    
    * {
      margin: 0;
      padding: 0;
      box-sizing: border-box;
    }
    
    body {
      font-family: 'Poppins', sans-serif;
      background: linear-gradient(135deg, #f5f7fa 0%, #c3cfe2 100%);
      min-height: 100vh;
      padding: 2rem;
      color: var(--dark);
    }
    
    .container {
      max-width: 1200px;
      margin: 0 auto;
      padding: 2rem;
      background: rgba(255, 255, 255, 0.9);
      border-radius: 20px;
      box-shadow: 0 10px 30px rgba(0, 0, 0, 0.1);
      backdrop-filter: blur(10px);
    }
    
    header {
      text-align: center;
      margin-bottom: 2rem;
    }
    
    .logo {
      font-size: 2.5rem;
      color: var(--primary);
      margin-bottom: 0.5rem;
      display: flex;
      align-items: center;
      justify-content: center;
      gap: 0.5rem;
    }
    
    h1 {
      color: var(--dark);
      margin-bottom: 0.5rem;
      font-weight: 600;
    }
    
    .subtitle {
      color: #666;
      margin-bottom: 2rem;
    }
    
    .control-section {
      margin-bottom: 3rem;
    }
    
    .section-title {
      font-size: 1.5rem;
      color: var(--primary);
      margin-bottom: 1.5rem;
      display: flex;
      align-items: center;
      gap: 0.8rem;
    }
    
    .dashboard {
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
      gap: 2rem;
      margin-bottom: 2rem;
    }
    
    .light-card {
      background: white;
      border-radius: 15px;
      padding: 1.5rem;
      box-shadow: 0 5px 15px rgba(0, 0, 0, 0.05);
      transition: transform 0.3s, box-shadow 0.3s;
    }
    
    .light-card:hover {
      transform: translateY(-5px);
      box-shadow: 0 10px 25px rgba(0, 0, 0, 0.1);
    }
    
    .light-icon {
      font-size: 2.5rem;
      margin-bottom: 1rem;
      color: var(--accent);
    }
    
    .light-name {
      font-size: 1.2rem;
      margin-bottom: 1rem;
      font-weight: 600;
    }
    
    .btn-group {
      display: flex;
      justify-content: center;
      gap: 1rem;
    }
    
    .btn {
      padding: 0.6rem 1.2rem;
      border: none;
      border-radius: 50px;
      font-size: 1rem;
      cursor: pointer;
      transition: all 0.3s;
      font-weight: 500;
      display: flex;
      align-items: center;
      gap: 0.5rem;
    }
    
    .btn-on {
      background: var(--success);
      color: white;
    }
    
    .btn-off {
      background: var(--danger);
      color: white;
    }
    
    .btn-auto {
      background: var(--info);
      color: white;
    }
    
    .btn:hover {
      transform: scale(1.05);
      opacity: 0.9;
    }
    
    .status-container {
      background: white;
      border-radius: 15px;
      padding: 1.5rem;
      margin-bottom: 2rem;
      box-shadow: 0 5px 15px rgba(0, 0, 0, 0.05);
    }
    
    .status-title {
      font-size: 1.2rem;
      margin-bottom: 1rem;
      font-weight: 600;
      color: var(--primary);
    }
    
    .status-grid {
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
      gap: 1rem;
    }
    
    .status-item {
      display: flex;
      align-items: center;
      gap: 0.8rem;
    }
    
    .status-icon {
      font-size: 1.2rem;
    }
    
    .connected {
      color: var(--success);
    }
    
    .disconnected {
      color: var(--danger);
    }
    
    .about-section {
      background: white;
      border-radius: 15px;
      padding: 1.5rem;
      margin-bottom: 2rem;
      box-shadow: 0 5px 15px rgba(0, 0, 0, 0.05);
    }
    
    .about-title {
      font-size: 1.2rem;
      margin-bottom: 1rem;
      font-weight: 600;
      color: var(--primary);
    }
    
    .about-text {
      line-height: 1.6;
      color: #555;
    }
    
    footer {
      text-align: center;
      margin-top: 3rem;
      color: #666;
      font-size: 0.9rem;
    }
    
    .footer-links {
      display: flex;
      justify-content: center;
      gap: 1.5rem;
      margin-top: 1rem;
    }
    
    .footer-link {
      color: var(--primary);
      text-decoration: none;
      transition: color 0.3s;
    }
    
    .footer-link:hover {
      color: var(--secondary);
    }
    
    @media (max-width: 768px) {
      .container {
        padding: 1rem;
      }
      
      .dashboard {
        grid-template-columns: 1fr;
      }
    }
  </style>
</head>
<body>
  <div class="container">
    <header>
      <div class="logo">
        <i class="fas fa-brain"></i> AN INTELLIGENT LIGHT SYSTEM
      </div>
      <h1>Gaspher-Light Control Dashboard</h1>
      <p class="subtitle">Combining automatic sensors and manual control for optimal lighting</p>
    </header>
    
    <div class="status-container">
      <div class="status-title">System Status</div>
      <div class="status-grid">
        <div class="status-item">
          <i class="fas fa-wifi status-icon connected"></i>
          <span>WiFi: SmartLight-AP</span>
        </div>
        <div class="status-item">
          <i class="fas fa-server status-icon connected"></i>
          <span>Server Running</span>
        </div>
        <div class="status-item">
          <i class="fas fa-lightbulb status-icon connected"></i>
          <span>3 Lights Connected</span>
        </div>
      </div>
    </div>
    
    <div class="control-section">
      <h2 class="section-title"><i class="fas fa-cogs"></i> Manual Control</h2>
      <div class="dashboard">
        <div class="light-card">
          <div class="light-icon">
            <i class="fas fa-lightbulb"></i>
          </div>
          <div class="light-name">Living Room Light</div>
          <div class="btn-group">
            <button class="btn btn-on" onclick="controlLight('led1', 'on')">
              <i class="fas fa-power-off"></i> ON
            </button>
            <button class="btn btn-off" onclick="controlLight('led1', 'off')">
              <i class="fas fa-power-off"></i> OFF
            </button>
          </div>
        </div>
        
        <div class="light-card">
          <div class="light-icon">
            <i class="fas fa-lightbulb"></i>
          </div>
          <div class="light-name">Kitchen Light</div>
          <div class="btn-group">
            <button class="btn btn-on" onclick="controlLight('led2', 'on')">
              <i class="fas fa-power-off"></i> ON
            </button>
            <button class="btn btn-off" onclick="controlLight('led2', 'off')">
              <i class="fas fa-power-off"></i> OFF
            </button>
          </div>
        </div>
        
        <div class="light-card">
          <div class="light-icon">
            <i class="fas fa-lightbulb"></i>
          </div>
          <div class="light-name">Bedroom Light</div>
          <div class="btn-group">
            <button class="btn btn-on" onclick="controlLight('led3', 'on')">
              <i class="fas fa-power-off"></i> ON
            </button>
            <button class="btn btn-off" onclick="controlLight('led3', 'off')">
              <i class="fas fa-power-off"></i> OFF
            </button>
          </div>
        </div>
      </div>
    </div>
    
    <div class="control-section">
      <h2 class="section-title"><i class="fas fa-robot"></i> Automatic Control</h2>
      <div class="dashboard">
        <div class="light-card">
          <div class="light-icon">
            <i class="fas fa-motion"></i>
          </div>
          <div class="light-name">Motion Detection</div>
          <div class="btn-group">
            <button class="btn btn-auto" onclick="setAutoMode('motion')">
              <i class="fas fa-walking"></i> Activate
            </button>
          </div>
        </div>
        
        <div class="light-card">
          <div class="light-icon">
            <i class="fas fa-sun"></i>
          </div>
          <div class="light-name">Daylight Sensor</div>
          <div class="btn-group">
            <button class="btn btn-auto" onclick="setAutoMode('daylight')">
              <i class="fas fa-cloud-sun"></i> Activate
            </button>
          </div>
        </div>
        
        <div class="light-card">
          <div class="light-icon">
            <i class="fas fa-clock"></i>
          </div>
          <div class="light-name">Schedule Timer</div>
          <div class="btn-group">
            <button class="btn btn-auto" onclick="setAutoMode('timer')">
              <i class="fas fa-calendar-alt"></i> Set Schedule
            </button>
          </div>
        </div>
      </div>
    </div>
    
    <div class="about-section">
      <div class="about-title">About Our Intelligent Light System</div>
      <div class="about-text">
        <p>This intelligent lighting system combines both manual and automatic control for optimal energy efficiency and convenience. The system features:</p>
        <ul style="margin-top: 1rem; padding-left: 1.5rem;">
          <li>Manual control of individual lights</li>
          <li>Motion-activated lighting</li>
          <li>Daylight sensing for natural light adjustment</li>
          <li>Scheduled lighting automation</li>
        </ul>
        <p style="margin-top: 1rem;">Connect to the <strong>GaspherLight-AP</strong> WiFi network to access this control panel from any device.</p>
      </div>
    </div>
    
    <footer>
      <p>© 2025 Intelligent Light System. All rights reserved.</p>
      <div class="footer-links">
        <a href="#" class="footer-link">Documentation</a>
        <a href="#" class="footer-link">Support</a>
        <a href="#" class="footer-link">System Settings</a>
      </div>
    </footer>
  </div>
  
  <script>
    function controlLight(led, action) {
      fetch(`/${led}/${action}`)
        .then(response => response.text())
        .then(data => {
          console.log(data);
          // Add visual feedback
          alert(data);
        })
        .catch(error => console.error('Error:', error));
    }
    
    function setAutoMode(mode) {
      fetch(`/automode/${mode}`)
        .then(response => response.text())
        .then(data => {
          console.log(data);
          alert(`Automatic mode activated: ${mode}`);
        })
        .catch(error => console.error('Error:', error));
    }
  </script>
</body>
</html>
)=====";

void setup() {
  Serial.begin(115200);

  // Set LED pins as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Start the Access Point
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Access Point started. Connect to Wi-Fi '");
  Serial.print(ssid);
  Serial.print("' and visit http://");
  Serial.println(IP);

  // Define routes
  server.on("/", []() {
    server.send(200, "text/html", webpage);
  });

  // Manual control routes
  server.on("/led1/on", []() { 
    digitalWrite(led1, HIGH); 
    server.send(200, "text/plain", "Living Room Light turned ON"); 
  });
  server.on("/led1/off", []() { 
    digitalWrite(led1, LOW); 
    server.send(200, "text/plain", "Living Room Light turned OFF"); 
  });

  server.on("/led2/on", []() { 
    digitalWrite(led2, HIGH); 
    server.send(200, "text/plain", "Kitchen Light turned ON"); 
  });
  server.on("/led2/off", []() { 
    digitalWrite(led2, LOW); 
    server.send(200, "text/plain", "Kitchen Light turned OFF"); 
  });

  server.on("/led3/on", []() { 
    digitalWrite(led3, HIGH); 
    server.send(200, "text/plain", "Bedroom Light turned ON"); 
  });
  server.on("/led3/off", []() { 
    digitalWrite(led3, LOW); 
    server.send(200, "text/plain", "Bedroom Light turned OFF"); 
  });

  // Automatic control routes
  server.on("/automode/motion", []() {
    // Here you would implement motion detection logic
    server.send(200, "text/plain", "Motion detection mode activated");
  });
  
  server.on("/automode/daylight", []() {
    // Here you would implement daylight sensing logic
    server.send(200, "text/plain", "Daylight sensing mode activated");
  });
  
  server.on("/automode/timer", []() {
    // Here you would implement timer/scheduling logic
    server.send(200, "text/plain", "Timer scheduling mode activated");
  });

  server.begin();
  Serial.println("Web server started!");
}

void loop() {
  server.handleClient();
}
