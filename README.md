# FedAllocation
Extended Allocation Module for Federation

Date: 3/18/2016
@author: Parshuram
Note: We have extended the existing DRF algorithm (HierarchicalDRFAllocatorProcess) to accomplish only the required module change (override) in the 'FederationAllocator' class. Here we have overridden the addFramework() method to verify the overridden method call is successfull or not. In future we will have only the required methods, the addFramework() might be there or not, we are not sure at this point of time. We are able to create a proper allocation module for the mesos. We ran and tested the loading of new allocation module to the mesos.
Please find the shell script (CompileRun.sh) to test this part/change (assuming you have mesos in your system)
Change the MESOS_HOME_DIR path before running the script
