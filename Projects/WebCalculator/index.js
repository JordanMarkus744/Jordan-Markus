var display = '0';
var total = 0;
var operatorClick = false;
var reset = false;
var operator = '';

function changeDisplay() {
    document.getElementById('display').innerText = display;
}

function applyOperator() {
    let currentValue = parseFloat(display);
    
    switch (operator) {
        case '+':
            total += currentValue;
            break;
        case '-':
            total -= currentValue;
            break;
        case '*':
            total *= currentValue;
            break;
        case '/':
            if (currentValue !== 0) {
                total /= currentValue;
            } else {
                alert("Cannot divide by zero");
                total = 0;
            }
            break;
        default:
            total = currentValue;
            break;
    }
    
    display = total.toString();
    changeDisplay();
}

function operatorClicked(char) {
    operatorClick = true;
    
    if (char === '=') {
        applyOperator();
        total = 0;
        reset = true;
        operatorClick = false;
        operator = '';
    } else {
        if (operator !== '') {
            applyOperator();
        }
        operator = char;
    }
}

function numberClicked(number) {
    if (operatorClick) {
        total = parseFloat(display);
        display = number.toString();
        operatorClick = false;
    } else {
        if (reset) {
            display = number.toString();
            total = parseFloat(display);
            reset = false;
        } else {
            if (display === '0') {
                display = number.toString();
            } else {
                display += number.toString();
            }
        }
    }
    changeDisplay();
}