#
#  Be sure to run `pod spec lint TYHNetworkMoudle.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#



Pod::Spec.new do |spec|

  spec.name         = "TYHNetworkMoudle"
  spec.version      = "0.0.7"
  spec.summary      = "TYHNetworkMoudle."
  spec.description  = 'The project is about TYHNetworkMoudle'

  spec.homepage     = "https://github.com/Shinkai123/TYHNetwork"


  spec.license      = { :type => "MIT", :file => "FILE_LICENSE" }



  spec.author             = { "tyh" => "1210480377@qq.com" }

  spec.swift_version = '4.2'
  spec.ios.deployment_target = "9.0"

  spec.source       = { :git => "https://github.com/Shinkai123/TYHNetwork.git", :tag => spec.version.to_s }


  # ――― Source Code ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  CocoaPods is smart about how it includes source code. For source files
  #  giving a folder will include any swift, h, m, mm, c & cpp files.
  #  For header files it will include any header in the folder.
  #  Not including the public_header_files will make all headers public.
  #

  spec.source_files  = "TYHNetworkMoudle/Classes/**/*{.swift}"


  #

  # spec.resource  = "icon.png"
  # spec.resources = "Resources/*.png"

  # spec.preserve_paths = "FilesToSave", "MoreFilesToSave"


  spec.dependency 'CTMediator'
  spec.dependency 'Alamofire'

end
