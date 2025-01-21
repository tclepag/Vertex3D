//
// Created by lepag on 1/17/2025.
//

#ifndef ISIGNAL_H
#define ISIGNAL_H

#include <cstddef>
#include <functional>

#include "VSignalSubscription.h"

using std::function;
using std::vector;

namespace Vertex3D {
    template <typename arguments>

    class VSignal {
        public:
        // Add a subscriber to this signal
        // Accepts lambdas: [](...) {}
        // Accepts functions: void funcName(...) {}
        // !!Keep in mind that these subscriptions do not return a value!!
        VSignalSubscription< arguments > subscribe( function< void( arguments ) > callback ) {
            auto subscription = VSignalSubscription< arguments >( callback );
            subscriptions.emplace_back( subscription );
            return subscription;
        }

        // Notifies all subscribers to this signal with provided arguments
        // !!IF YOU FAIL TO PROVIDE THE VALUES EXPECTED IN THE DECLARATION OF THIS
        // SIGNAL THEN IT WILL FAIL
        // IF YOU WISH TO PROVIDE OPTIONAL ARGUMENTS USE std::variant<argumentTypeUWant, std::monostate>!!
        void publish( arguments message ) {
            if ( subscriptions.empty() ) {
                return;
            }
            for ( VSignalSubscription< arguments > subscriber : subscriptions ) {
                subscriber.notify( message );
            }
        }

        // Destroys all subscribers and clears this signal
        ~VSignal() {
            for ( VSignalSubscription< arguments > subscriber : subscriptions ) {
                subscriber.~VSignalSubscription();
            }
            this->subscriptions.clear();
        };
    private:
        // Vector of all subscribers to this signal
        vector< VSignalSubscription< arguments > > subscriptions;
    };
}

#endif //ISIGNAL_H
