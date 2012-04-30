desc "Build everything"
task :build do
  system 'make clean'
  system 'cd lib/libsass && make && cd ../..'
  system 'phpize'
  system './configure'
  system 'make'
  system 'make test'
end

task :default => :build