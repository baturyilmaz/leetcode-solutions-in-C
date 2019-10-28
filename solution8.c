int myAtoi(char * str){

    int stringLength = strlen(str), found = 0, returnNumber = 0, i = 0, sign = 0, numberLength = 0, num = 0;
        
    while (!found && i < stringLength)
    {
        if (str[i] > 47 && str[i] < 58)
        { 
           found = 5;
        }
        else if (str [i] == 43 || str[i] == 45)
        {   
            if(sign == 0 && str[i + 1] > 47 && str[i + 1] < 58)
                sign = str[i] == 43 ? 1 : -1;
            else
                return 0;
        }
        else if (str[i] != 32)
        {    
            return 0;
        }
        i++;
    }

    i--;
    while (found && i < stringLength && str[i] >= 48 && str[i] < 58)
    {
        num = str[i] - 48;
        
        if (returnNumber <= 214748363)
        {
            returnNumber = returnNumber * 10 + num;
        }
        else if ((sign == 1 || sign == 0) && num <= 7 && returnNumber == 214748364)
        {
            return returnNumber = returnNumber * 10 + num;
        }    
        else if (sign == -1 && num <= 8 && returnNumber == 214748364)
        {
            num *= -1;
            returnNumber *= -1;
            return returnNumber = returnNumber * 10 + num;
        }
        else
        {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        
        i++;
    }
    
    return sign == -1 ? returnNumber * -1 : returnNumber;
}
