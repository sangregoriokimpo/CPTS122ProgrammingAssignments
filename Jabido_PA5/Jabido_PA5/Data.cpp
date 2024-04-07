//
// Created by Gregory Jabido on 3/5/24.
//

/*************************************************************
* Function: run_system ()
* Date Created:
* Date Last Modified:
* Description:
* Input parameters:
* Returns:
* Preconditions:
* Postconditions:
*************************************************************/

#include "Data.h"

/*************************************************************
* Function: getCustomerNumber() const
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Returns the customer number associated with the
* Data object.
* Input parameters: None
* Returns: Integer representing the customer number.
* Preconditions: The Data object must be properly initialized.
* Postconditions: None
*************************************************************/

int Data::getCustomerNumber() const {
    return customerNumber;
}

/*************************************************************
* Function: setCustomerNumber(int customerNumber)
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Sets the customer number associated
* with the Data object.
* Input parameters:
*   - customerNumber: Integer representing the
*  customer number to set.
* Returns: Void
* Preconditions: None
* Postconditions: The customer number of the Data object is
* updated.
*************************************************************/

void Data::setCustomerNumber(int customerNumber) {
    Data::customerNumber = customerNumber;
}

/*************************************************************
* Function: getServiceTime() const
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Returns the service time associated with
* the Data object.
* Input parameters: None
* Returns: Integer representing the service time.
* Preconditions: The Data object must be properly initialized.
* Postconditions: None
*************************************************************/

int Data::getServiceTime() const {
    return serviceTime;
}

/*************************************************************
* Function: setServiceTime(int serviceTime)
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Sets the service time associated with the
* Data object.
* Input parameters:
*  - serviceTime: Integer representing the service time to set.
* Returns: Void
* Preconditions: None
* Postconditions: The service time of the Data object is
* updated.
*************************************************************/

void Data::setServiceTime(int serviceTime) {
    Data::serviceTime = serviceTime;
}

/*************************************************************
* Function: getTotalTime() const
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Returns the total time associated with the
* Data object.
* Input parameters: None
* Returns: Integer representing the total time.
* Preconditions: The Data object must be properly initialized.
* Postconditions: None
*************************************************************/

int Data::getTotalTime() const {
    return totalTime;
}

/*************************************************************
* Function: setTotalTime(int totalTime)
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Sets the total time associated with the Data
* object.
* Input parameters:
*   - totalTime: Integer representing the total time to set.
* Returns: Void
* Preconditions: None
* Postconditions: The total time of the Data object is updated.
*************************************************************/

void Data::setTotalTime(int totalTime) {
    Data::totalTime = totalTime;
}

/*************************************************************
* Function: Data(int customerNumber, int serviceTime)
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Constructor for the Data class. Initializes
* customerNumber and serviceTime.
* Input parameters:
*   - customerNumber: Integer representing the customer
*   number to set.
*   - serviceTime: Integer representing the service
*   time to set.
* Returns: N/A
* Preconditions: None
* Postconditions: The Data object is properly initialized
* with the provided customerNumber and serviceTime.
*************************************************************/

Data::Data(int customerNumber, int serviceTime) : customerNumber(customerNumber), serviceTime(serviceTime) {}

/*************************************************************
* Function: Data()
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Default constructor for the Data class.
* Initializes customerNumber, serviceTime, and totalTime to 0.
* Input parameters: None
* Returns: N/A
* Preconditions: None
* Postconditions: The Data object is properly initialized
* with customerNumber, serviceTime, and totalTime set to 0.
*************************************************************/

Data::Data() {
    this->customerNumber = 0;
    this->serviceTime = 0;
    this->totalTime = 0;
}

/*************************************************************
* Function: Data(int customerNumber)
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Constructor for the Data class. Initializes
* customerNumber, serviceTime, and totalTime.
* Input parameters:
*   - customerNumber: Integer representing the customer number.
* Returns: N/A
* Preconditions: None
* Postconditions: The Data object is properly initialized with
* customerNumber set and serviceTime and totalTime set to 0.
*************************************************************/

Data::Data(int customerNumber) {
    this->customerNumber = customerNumber;
    this->serviceTime = 0;
    this->totalTime = 0;
}

/*************************************************************
* Function: decrementServiceTime()
* Date Created: 3/9/24
* Date Last Modified: 3/9/24
* Description: Decrements the service time of the Data object if it's greater than 0.
* Input parameters: None
* Returns: Void
* Preconditions: None
* Postconditions: If the service time is greater than 0, it is decremented by 1.
*************************************************************/

void Data::decrementServiceTime() {
    /*if (this->getServiceTime() > 0) {
        this->serviceTime--;
    }*/

    if (this != nullptr && this->getServiceTime() > 0) {
        this->serviceTime--;
    }
}
