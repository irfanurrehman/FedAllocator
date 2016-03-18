#ifndef __MASTER_ALLOCATOR_MESOS_HIERARCHICAL_FILTER_HPP__
#define __MASTER_ALLOCATOR_MESOS_HIERARCHICAL_FILTER_HPP__

#include <mesos/mesos.hpp>
#include <mesos/module.hpp>

#include <mesos/master/allocator.hpp>
#include <mesos/module/allocator.hpp>

#include "master/allocator/mesos/hierarchical.hpp"
#include "master/allocator/sorter/drf/sorter.hpp"

#include "master/constants.hpp"
#include <stout/try.hpp>


using namespace mesos;
using mesos::master::allocator::Allocator;
using mesos::internal::master::allocator::HierarchicalDRFAllocator;
using mesos::internal::master::allocator::DRFSorter;
using mesos::internal::master::allocator::MesosAllocator;
using mesos::internal::master::allocator::HierarchicalAllocatorProcess;


class FederationAllocator;
typedef HierarchicalAllocatorProcess<DRFSorter, DRFSorter> HierarchicalDRFAllocatorProcess;
typedef MesosAllocator<FederationAllocator> FilterOffersFedAlloc;


class FederationAllocator : public HierarchicalDRFAllocatorProcess 
{
  public:
    virtual ~FederationAllocator() {}
    virtual void addFramework(const FrameworkID& frameworkId,
			      const FrameworkInfo& frameworkInfo,
			      const hashmap<SlaveID, Resources>& used);


}; // class FilterFramework

#endif // __MASTER_ALLOCATOR_MESOS_HIERARCHICAL_FILTER_HPP__
