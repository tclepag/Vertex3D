//
// Created by lepag on 1/17/2025.
//

#ifndef ISIGNALSUBSCRIPTION_H
#define ISIGNALSUBSCRIPTION_H

#include <functional>
using std::function;

namespace Vertex3D {
    template <typename arguments>
    class ISignalSubscription {
    public:

        // Create a signal with provided arguments
        // "ISignal.h" USES THIS AS THE BASE HANDLER FOR CALLBACKS
        explicit ISignalSubscription( function< void( arguments ) > func ) {
            this->subscriber = func;
        }

        // Runs the callback with provided arguments
        // "ISignal.h" USES THIS AS THE BASE HANDLER FOR CALLBACKS
        void notify( const arguments arg ) {
            subscriber( arg );
        }

        // Clears this subscriber
        // "ISignal.h" USES THIS AS THE BASE HANDLER FOR CALLBACKS
        ~ISignalSubscription() = default;
    private:
        // The callback attached to this subscription
        function< void( arguments ) > subscriber;
    };
}

#endif //ISIGNALSUBSCRIPTION_H
