


function submitForm(){

    const email = document.getElementById("email").value;
    let checkboxes = document.querySelectorAll('.CB');
    let streamingPlatforms = [];
    
    checkboxes.forEach(function(checkbox) {
        if (checkbox.checked) {
            streamingPlatforms.push(checkbox.value);
        }
    });
    
    let countries = document.querySelectorAll('.country');
    let country = "";
    countries.forEach(function(radio) {
        if (radio.checked) {
            country = radio.value;
        }
    });
    
    let textArea = document.getElementById('Keywords').value;
    let Keywords = textArea.split(/\s+/);

    let orders = document.querySelectorAll('.order');
    let order;
    orders.forEach(function(ord){
        if (ord.checked){
            order = ord.id;
        }
    });


    let mysql = require('mysql');

    let connection = mysql.createConnection({
        host: "MoviesDatabase",
        port: "3306",
        user: "root",
        password: "f82kdhadjkf882364kd9543",
        database: "movieemailerdb"
    });

    // CONNECTING TO DATABASE
    connection.connect((err)=>  {
        if (err) return console.error(err.message);
    
        let sql = "SELECT * FROM users WHERE email = ?";
        let data = [email];
        connection.query(sql, data, (error, results, fields) => {
            if (error){
                console.error("Error querying database:", error);
            }
            if (results.length > 0){
                console.log("email already exists! Updating...");
                sql = "UPDATE users SET numberOfForms = numberOfForms + 1 WHERE email = ?";
                data = [email];
                connection.query(sql,data,(error,results,fields)=>{
                    console.log("Updated users table!");
                });
                let id = "SELECT id FROM users WHERE email = ?";
                data = [email];
                connection.query(sql,data,(error,results,fields)=>{
                    if (error){
                        console.error("Error executing query:", error);
                    }
                    else{
                        if (results.length > 0){
                            const userId = results[0].id;
                            console.log("User ID:", userId);
                            let updateQuery = "SELECT * FROM platforms WHERE id = ?";
                            let updateData = [userId];
                            connection.query(updateQuery, updateData, (error,result,fields)=>{
                                if (error){
                                    console.error("Error getting platforms with certain ID's");
                                }
                                else{
                                    let platformsCAP = 5;
                                    if (result.length > 0){
                                        let count = 0;
                                        for (let i = 0; i < result.length; i++){
                                            let platformUpdateQuery = "UPDATE platforms SET platform = ? WHERE id = ?";
                                            let platformUpdateData = [result[i].platform, result[i].id];
                                            connection.query(platformUpdateQuery, platformUpdateData, (error, updateResults, fields) => {
                                                if (error) {
                                                    console.error("Error updating platform:", error);
                                                } else {
                                                    console.log("Platform updated successfully:", updateResult.affectedRows, "rows affected");
                                                }
                                            })
                                        }
                                    }
                                }
                            });
                            
                        }
                    }
                });
            }
        });
    });


}