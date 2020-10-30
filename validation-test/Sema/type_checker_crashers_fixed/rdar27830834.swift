// RUN: %target-swift-frontend %s -typecheck

var d = [String:String]()
_ = "\(d.map{ [$0 : $0] })"
// expected-error@-1 {{type 'Dictionary<String, String>.Element' (aka '(key: String, value: String)') cannot conform to 'Hashable'; only concrete types such as structs, enums and classes can conform to protocols}}
// expected-note@-2 {{required by generic struct 'Dictionary' where 'Key' = 'Dictionary<String, String>.Element' (aka '(key: String, value: String)')}}
