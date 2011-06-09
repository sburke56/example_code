#ifndef _EVTIDS_H_
#define _EVTIDS_H_

namespace events{
namespace progress{

const size_t IdNumOperations     = QEvent::User + 1; 
const size_t IdStep              = QEvent::User + 2; 
const size_t IdCompleted         = QEvent::User + 3; 
const size_t IdCanceled          = QEvent::User + 4; 
const size_t IdSpawnThread       = QEvent::User + 5; 
}
}
#endif /* _EVTIDS_H_ */
