
Pod::Spec.new do |s|


  s.name         = "CosmoseSDK"
  s.version      = "0.9.1"
  s.summary      = "iOS SDK for Cosmose app partners."

  s.homepage     = "http://cosmose.co"
  s.platform     = :ios, '7.0'

  s.source       = { :git => "https://github.com/Cosmose/cosmose-ios-sdk.git" }

  s.source_files =  'CosmoseSDK/Headers/*.h'
  s.preserve_paths = 'CosmoseSDK/libCosmoseSDK.a'
  s.vendored_libraries = 'CosmoseSDK/libCosmoseSDK.a'

  s.requires_arc = true

  s.frameworks = 'CoreLocation'

  s.dependency 'AFNetworking', '~> 2.2.0'
  s.dependency 'EGODatabase', '~> 2.0'
  s.dependency 'JSONKit-NoWarning', '~> 1.1'
  s.dependency 'MSSpec', '~> 0.1.1'
  s.dependency 'Facebook-iOS-SDK', '~> 3.12.0'

end
