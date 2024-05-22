CREATE TABLE users (
  id INT AUTO_INCREMENT PRIMARY KEY,
  email VARCHAR(100) NOT NULL UNIQUE,
  numberOfForms INT DEFAULT 0
);

CREATE TABLE platforms(
  platform_id INT,
  platform VARCHAR(255),
  FOREIGN KEY (platform_id) REFERENCES users(id)
);