#include <iostream>
#include <mesos/master/allocator.hpp>
#include <mesos/module/allocator.hpp>
#include <stout/try.hpp>

#include "FedAllocator.hpp"

using namespace mesos;
using mesos::master::allocator::Allocator;


void FederationAllocator::addFramework(const FrameworkID& frameworkId, 
				   const FrameworkInfo& frameworkInfo, 
				   const hashmap<SlaveID, Resources>& used)
{
    std::cout << "   :::::: HC#03 -- OUR addFramework method is called" << std::endl;
}

void FederationAllocator::updateGlobalValue(int val)
{
    std::cout << "%%%% [before] The current value of Global var 'fedVal' = " << fedVal << std::endl;
    // update new value here now
    fedVal = val;
    std::cout << "%%%% [after] The current value of Global var 'fedVal' = " << fedVal << std::endl;
}

int FederationAllocator::getGlobalValue()
{
        return fedVal;
}


static Allocator* createAllocator(const Parameters& parameters)
{
    std::cout << "   :::::: HC#01 --  BEFORE createAllocator()" << std::endl;

    Try<Allocator*> allocator = FilterOffersFedAlloc::create();

    if (allocator.isError()) 
    {
       return NULL;
    }
    std::cout << "   :::::: HC#02 --  AFTER createAllocator()" << std::endl;

    return allocator.get();
}


mesos::modules::Module<Allocator> FedAllocatorModule (MESOS_MODULE_API_VERSION, MESOS_VERSION, "Huawei Mesos Federation Project", "parushuram.k@huawei.com", "Cloud Federation Allocator Module.", NULL, createAllocator);

