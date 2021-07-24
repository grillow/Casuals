project('Casuals', 'cpp',
  version : '0.1',
  default_options : ['warning_level=0', 'cpp_std=c++14'])

sfml_dep = dependency('sfml-all', fallback : ['sfml', 'sfml_dep'])

executable('Casuals',
           'Casuals/Block.cpp',
           'Casuals/Bullet.cpp',
           'Casuals/CollidableRectangle.cpp',
           'Casuals/Entity.cpp',
           'Casuals/EntityManager.cpp',
           'Casuals/Game.cpp',
           'Casuals/GameInput.cpp',
           'Casuals/Input.cpp',
           'Casuals/Light.cpp',
           'Casuals/LightSource.cpp',
           'Casuals/Main.cpp',
           'Casuals/Map.cpp',
           'Casuals/Map_Duel.cpp',
           'Casuals/Map_Josh.cpp',
           'Casuals/MapManager.cpp',
           'Casuals/Map_Polygon.cpp',
           'Casuals/Ray.cpp',
           'Casuals/RenderUtils.cpp',
           'Casuals/SPlayer.cpp',
           dependencies : [ sfml_dep ],
           install : true)
