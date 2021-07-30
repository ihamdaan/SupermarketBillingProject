#include<stdio.h>
#include<string.h>
//time.h header file is used to get & manipulate system time
#include <time.h>


// various color functions are used to avoid overwriting of the same code
void red () {
    //ANSI (American National Standards Institute) color code / color logging for red
    printf("\033[1;31m");
    //successive standards
}

void yellow () {
    //ANSI color code / color logging for yellow
    printf("\033[1;33m");
    //successive standards
}

void green () {
    //ANSI color code / color logging for green
    printf("\033[0;32m");
    //successive standards
}

void cyanColor () {
    //ANSI color code / color logging for cyan
    printf("\033[0;36m");
    //successive standards
}


//reset function will change the text color to its default color i.e., white
void reset () {
    //ANSI color code / color logging for default, white
    printf("\033[0m");
    //successive standards
}

// a 'amount' function is created to calculate the total amount spent by the customer
float amount(float rate, int quantity, float discount, float vat);

void main()
{
	int j, quantity, cash, w = 0;
	long cash_received, newt_amount;
	float rate, discount, vat, t_amount=0, amount1, float_part;
    // Item code is used as string to compare it with the given list
	char itemcode[5], itemname[20];

    //Header of the Cash Memo displaying Branding and Address of the shop
    printf("\n\n\n");
    yellow ();
	printf("\t\t\t\tF A R M A I S H I   S U P E R M A R K E T\n");
	printf("\t\t\t\t  S3, Horola, Deep Complex Sharma Mkt,\n");
	printf("\t\t\t\t  Opp Sector 6 Bus Stand, Noida, Delhi\n");
    reset ();


	printf("----------------------------------------------------------------------------------------------------------------\n\n");

    //Different Items are placed under sale option with reduced prices
	red();
    printf("Please Press the desired number respectively to add items to customer's bill\n\n");
    reset();
    printf("OUR TOP PRODUCTS AVAILABLE FOR SALE AT STORE:\n\n");

    red();
    //It is not necessary to have all items on sale in a store, thus we have 'n' option to add
    //customers desired product to the billing list
    printf(" (n) -- If you dont find your Item in the list, try entering it manually. It might have been exempted from the Sale\n");
    reset();

	printf(" (1) -- Chinese Manchurian - Instant Noodles (100 gm) @ Rs.10.00\t\t\t\t\t @ 0.25%s VAT\n", "%");
	printf(" (2) -- Cadbury Silk Chocolates - Pack Of 10 @ Rs.800.00\t\t\t\t@ 20%s discount\t @ 9%s VAT\n", "%", "%");
	printf(" (3) -- Heat Resistant Plastic Water Bottle - (750 ml) @ Rs.999.00\t\t\t@ 10%s discount\t @ 9.3%s VAT\n", "%", "%");
	printf(" (4) -- Medically Certified Cavity Protection Toothpaste (75 ml) @ Rs.93.05\t\t@ 2%s discount\t @ 4.5%s VAT\n", "%", "%");
	printf(" (5) -- Basmati Long Grain Biryani Rice (1 kg) @ Rs.110.00\t\t\t\t\t\t @ 0.25%s VAT\n", "%");
	printf(" (6) -- Whole Wheat Chakki Fresh Atta (5 kg) @ Rs.226.00\t\t\t\t@ 10%s discount\t @ 9.3%s VAT\n", "%", "%");
	printf(" (7) -- Healthy Refined Edible Oil (2 ltr) @ Rs.209.95\t\t\t\t\t@ 2%s discount\t @ 4.5%s VAT\n", "%", "%");
	printf(" (8) -- Super Flexy tooth brush @ Rs.17.00\t\t\t\t\t\t@ 4%s discount\t @ 3%s VAT\n", "%", "%");
	printf(" (9) -- Tennis ball - Pack of 12 @ Rs.810.00\t\t\t\t\t\t@ 12%s discount\t @ 8.75%s VAT\n", "%", "%");
	printf(" (10) -- Anti Dandruff Smooth and Silky Shampoo (375ml bottle) @ Rs.290.00\t\t@ 25%s discount\t @ 2.5%s VAT\n", "%", "%");
    printf("\n");

    red();
    //To exit the cash Memo
    printf(" Press 'k' -- To exit Invoice / To Stop Entering More data\n");
    reset();


	printf("\n----------------------------------------------------------------------------------------------------------------\n");

    //the time.h header file is used here to priovide date and time accurately to the bill
    //without any manual labour/entry
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("\n");
    green();
    //Date gets displayed in dd-mm-yyyy format
    //Time gets displayed in hh:mm format
    printf("\t\t\t\t\t\t\t\t\t\tBilling Date/Time: %d-%02d-%02d %02d:%02d\n", tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900 , tm.tm_hour, tm.tm_min);
    printf("\n");
    reset();

    cyanColor();
	printf("\t\t\t\t\tCASH MEMO - RETAIL INVOICE\n");


	printf("----------------------------------------------------------------------------------------------------------------\n");


	printf("CODE\t\t\t\t\tITEM NAME\t\t\tQUANTITY");
	printf("\t\tAMOUNT(Rs.)\n");


	printf("----------------------------------------------------------------------------------------------------------------\n");


    reset();

    // A for loop is run from j = 1 to infinite unless we have j != 0 or j < 0 which will
    // terminate the loop
	for(j = 1; j!= 0; j++)
	{
        //fgets(string, size, stdin)
		fgets(itemcode, 5, stdin);
        /* fgets() reads input from user, we need to provide input during runtime. 
        Reads characters from the standard input (stdin) and stores them as a C string into str 
        until a newline character or the end-of-file is reached. */

        // The entered string in the form of item code is compared with 
        // pre-defined item code saved in the sale list from 1-10, n & k
		if(strcmp(itemcode, "1\n") == 0)
		{
			printf("\t\t\tChinese Manchurian- Instant Noodles 100gm\t  ");
			scanf("%d", &quantity);

            /*getchar is a function in C programming language that reads a single character 
            from the standard input stream stdin, regardless of what it is, and returns it to 
            the program*/
			getchar();
            // rate, discount & vat is pre-defined for the items available in sale list
			rate = 10.00;
			discount = 0.5;
			vat = 0.25;
            // All the various factors like rate, quantity, discount & vat is used to calculate 
            // final output
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t\t\t\t\t\t\t\t\t\t\t\t  %0.2f\n", amount1);
            // After amount being calculated respective to its quantity, it is added to 
            // total amount variable so to provide a gross amount
			t_amount += amount1;
            // Quantity is also increased respectively to provide a total QTY at end
			w += quantity;
		}

		else if(strcmp(itemcode, "2\n") == 0)
		{
			printf("\t\t\tMilkyBar Chocolates - Pack Of 10\t\t  ");
			scanf("%d", &quantity);
			getchar();

            // Rates, Discounts, VATS are different for all products accordingly
			rate = 800.00;
			discount = 20;
			vat = 9;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t\t\t\t\t\t\t\t\t\t\t\t  %0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}

		else if(strcmp(itemcode, "3\n") == 0)
		{
			printf("\t\tHeat Resistant Plastic Water Bottle - 750 ml\t\t  ");
			scanf("%d", &quantity);

            // Since getchar takes only one input at a time, it helps in avoiding compications
            // in running the loop
			getchar();
			rate = 999.00;
			discount = 10;
			vat = 9.3;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t\t\t\t\t\t\t\t\t\t\t\t  %0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}

		else if(strcmp(itemcode, "4\n") == 0)
		{
			printf("\tMedically Certified Cavity Protection Toothpaste (75 ml)\t  ");
			scanf("%d", &quantity);
			getchar();
			rate = 93.05;
			discount = 3;
			vat = 9;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t\t\t\t\t\t\t\t\t\t\t\t  %0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}

		else if(strcmp(itemcode, "5\n") == 0)
		{
			printf("\t\t\tBasmati Long Grain Biryani Rice 1 kg\t\t  ");
			scanf("%d", &quantity);
			getchar();
			rate = 110.00;
			discount = 6;
			vat = 4.5;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t\t\t\t\t\t\t\t\t\t\t\t  %0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}

		else if(strcmp(itemcode, "6\n") == 0)
		{
			printf("\t\t\tWhole Wheat Chakki Fresh Atta 5 kg\t\t  ");
			scanf("%d", &quantity);
			getchar();
			rate = 226.00;
			discount = 7;
			vat = 9.3;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t\t\t\t\t\t\t\t\t\t\t\t  %0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}

		else if(strcmp(itemcode, "7\n") == 0)
		{
			printf("\t\t\tHealthy Refined Edible Oil (2 ltr)\t\t  ");
			scanf("%d", &quantity);
			getchar();
			rate = 209.95;
			discount = 2;
			vat = 4.5;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t\t\t\t\t\t\t\t\t\t\t\t  %0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}

		else if(strcmp(itemcode, "8\n") == 0)
		{
			printf("\t\t\t\tSuper-Flexy toothbrush\t\t\t  ");
			scanf("%d", &quantity);
			getchar();
			rate = 17.00;
			discount = 4;
			vat = 3;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t\t\t\t\t\t\t\t\t\t\t\t  %0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}

		else if(strcmp(itemcode, "9\n") == 0)
		{
			printf("\t\t\t\tTennis ball - Pack of 12\t\t  ");
			scanf("%d", &quantity);
			getchar();
			rate = 810.00;
			discount = 12;
			vat = 8.75;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t\t\t\t\t\t\t\t\t\t\t\t  %0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}

		else if(strcmp(itemcode, "10\n") == 0)
		{
			printf("\t\t\tAnti Dandruff Smooth and Silky Shampoo\t\t  ");
			scanf("%d", &quantity);
			getchar();
			rate = 290.00;
			discount = 18;
			vat = 14;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t\t\t\t\t\t\t\t\t\t\t\t  %0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}

        // We have a 'n' option as specified earlier
        // To add items which is not present in the existing list
        else if(strcmp(itemcode, "n\n") == 0)
		{
            green();

            // To enter item name individually
            printf("\t\t\t\t Item: ");
            //fgets function here takes input of whole line along with the spaces present in it
            // It reads the functions as string buntill new line is entered
            fgets(itemname, sizeof(itemname), stdin);

            // To enter quantity
            printf("\t\t\t\t\t\t\t\t\tQty: ");
            scanf("%d", &quantity);

            // Since the item is not specified, Rate must be also given by the cashier
            printf("\t\t\t\t\t\t\t\t\t\t\t\tRate: ");
            scanf("%f",&rate);
            reset();
            getchar();
            discount = 2;
            vat = 6;    
            amount1 = amount(rate, quantity, discount, vat);
            printf("\t\t\t\t\t\t\t\t\t\t\t\t  %0.2f\n", amount1);
            t_amount += amount1;
            w += quantity;
            // Similarly the total amount is calculated along with the final rate including
            // taxes and reducing discounted amount
            // Also the amount and quantity is increased for this too
		}

		else if(strcmp(itemcode, "k\n") == 0)
		{
            //'k' input will term,inate the for loop proceeding the memo further to its calculation

            red ();
            // Before exitng the cash memo, this option will print the total amount of the 
            // products bought by the customer which was added using t_amount
			printf("\nTOTAL AMOUNT : \tRs %0.2f\n", t_amount);
            // float is used to print exact amount of money in decimal as well
            reset();

            cyanColor();
			printf("\n================================================================================================================\n");
            reset();
            // As mentioned above, j != 0 or j < 0 will terminate the program
			j = -1;
		}

		else
		{
            //if the input entered matches none, this will be printed as the output
            red();
			printf("\t\t\t\t\tPRODUCT DOES NOT EXIST\n");
            reset();
		}
	}

    // The given statement will print the total no of QTY pusrchased which was calculated
    // using w variable in the loop
	printf("\nTotal number of items sold = %d\n\n", w);

    // Amount to be paid
	printf("BALANCE DUE                = %0.2f\n\n", t_amount);

    // Since we cannot pay in decimals like 0.37, 0.56 etc; we round it off to its nearest whole number 
	newt_amount = t_amount;
	float_part = t_amount - newt_amount;

    /* if the decimal amount is less than 0.5 then the price gets rounded off to its lowest whole number 
    whereas, if it is greater than 0.5 then it round off to greater whole number */
	if(float_part > 0.50)
		newt_amount += 1;

    //Balance left after rounding off the amount
	printf("BALANCE DUE AFTER ROUNDING = %ld\n\n", newt_amount);

    // label A is used to print back the same thing if the given amount by the customer is less
	A:

	printf("CASH RECEIVED              = ");
	scanf("%ld", &cash_received);

	if(cash_received < newt_amount)
	{
		printf("Amount insufficient. Please provide more money.\n\n");
        // get back to A and print the insufficient amount
		goto A;
	}

    red();
    // if the given amount is exceeding the total amount, print the Cash to be returned back
	printf("\nCHANGE TO BE RETURNED      = %ld\n", cash_received - newt_amount);
    reset();


    // Footer of the Billing Cash Memo
    printf("\n");
	printf("----------------------------------------------------------------------------------------------------------------\n");
    yellow();
    printf("\n\n\t\t\t\tF A R M A I S H I   S U P E R M A R K E T\n");
	printf("\t\t\t         Customer Care Phone # : 1800 211 7821\n");
	printf("\t\t\t        Customer Care E-mail : farmaish@gmail.com\n");
	printf("\t\t\t             Store Phone # : 060-62621762\n");
	printf("\n\t\t\t             CALL FOR FREE HOME DELIVERY.\n");
	printf("\n\t\t\t\t            No cash refunds.\n");
	printf("\t\t\t              Terms and conditions apply.\n");
	printf("\t\t\t          ** Thank you for shopping with us **\n");
    printf("\t\t\t                  ~~ Visit Again!!! ~~\n");
	printf("\n*Any good purchased can be exchanged along with presenting the ORIGINAL cash memo within 15 days of purchase only.\n\n\n");
    reset();
}

// This will calculate the total amount using rate, qty, discount, vat
float amount(float p, int q, float r, float s)
{
    // p --> rate
    // q --> quantity
    // r --> discount
    // s --> vat

    // z --> to store the final amount
	float z;

    /* Total Amount = ((rate * quantity) - (rate * quantity * discount / 100)) 
                      + (((rate * quantity) - (rate * quantity * discount / 100)) * VAT / 100); */
	z = ((p * q) - (p * q * r / 100)) + (((p * q) - (p * q * r / 100)) * s / 100);
	return z;
}