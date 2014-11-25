Pod::Spec.new do |s|

  s.name         = "BigInteger"
  s.version      = "1.0.1"
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.summary      = "BigInteger(大数据处理)."
  s.homepage     = "https://github.com/p709723778/BigInteger"
  s.author             = { "Soto" => "p709723778@126.com" }
  s.source       = { :git => "https://github.com/p709723778/BigInteger.git", :tag => s.version.to_s }
  s.requires_arc = true
  s.description  = <<-DESC
                   该工程有两个大数据处理类 一个是调用C代码写的OC操作类来进行处理,另一个是原生OC代码(ARC)处理! 看各自爱好选择!
                   DESC

  # s.platform     = :ios
  # s.platform     = :ios, '5.0'
  # s.ios.deployment_target = '5.0'
  # s.osx.deployment_target = '10.7'
  

  s.public_header_files = 'BigInteger/**/*.h'
  #s.source_files  = 'BigInteger', 'BigInteger/**/*.{h,m}'
  #s.exclude_files = 'BigInteger/Exclude'

  s.subspec 'JKBigInteger' do |ss|
    ss.source_files = 'BigInteger/JKBigInteger/JK{BigInteger}.{h,m}','BigInteger/JKBigInteger/LibTomMath/tommath{_class,_superclass}.{h,c}','BigInteger/JKBigInteger/LibTomMath/tommath.{h}'
    #ss.ios.frameworks = 'Foundation', 'CoreGraphics'
    #ss.osx.frameworks = 'CoreServices'
  end
  
  s.subspec 'STBigInteger' do |ss|
    ss.source_files = 'BigInteger/STBigInteger/ST{BigInteger}.{h,m}','BigInteger/STBigInteger/NSString+HexToBytes.{h,m}'
    #ss.ios.frameworks = 'Foundation', 'CoreGraphics'
    #ss.osx.frameworks = 'CoreServices'
  end
  
   s.framework  = 'Foundation'
   s.frameworks = 'Foundation', 'UIKit'

end
