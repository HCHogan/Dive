import Foundation

@propertyWrapper
struct mywrapper {
    var storedValue: Int = 0
    var wrappedValue:Int {
        set {
            storedValue = newValue
        }
        get {
            storedValue
        }
    }
}

@mywrapper var hehe: Int
