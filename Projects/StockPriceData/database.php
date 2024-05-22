<?
class Database {
    private $host = "database_hostname";
    private $db_name = "database_name";
    private $username = "database_username";
    private $password = "database_user_password";
    private $conn;

    public function getConnection() {
        $this->conn = null;

        $this->conn = new mysqli($this->host, $this->username, $this->password, $this->db_name);
        if($this->conn->connect_error) {
            die("Connection failed.".$this->conn->connect_error);
        }
        return $this->conn;
    }
}
?>