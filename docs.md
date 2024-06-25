# Project Documentation

## src/Area.cpp
### getTilesetCoords
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | columns | N/A |
| int | id | N/A |

**Return Type:** Vector2u (N/A)


### angleBetween
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Vector2f | vec1 | N/A |
| Vector2f | vec2 | N/A |

**Return Type:** float (N/A)


### magnitude
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Vector2f | vec | N/A |

**Return Type:** float (N/A)


### dotProduct
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Vector2f | vec1 | N/A |
| Vector2f | vec2 | N/A |

**Return Type:** float (N/A)


### vectorFromAngle
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| float | angle | N/A |

**Return Type:** Vector2f (N/A)


### getMinMax
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Vector2f | vec | A vector that you are finding the min/max of |
| const vector<Vector2f>& | points | The points that we are getting the dot products of |

**Return Type:** MinMax ( A datatype that holds the min and max dotproducts)


### addUnique
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Vector2f | vec | The vector we might add to anglesToCheck |
| vector<float>& | anglesToCheck | N/A |

**Return Type:** void (N/A)


### Area::Area
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | N/A |
| string | path | N/A |
| vector<EnemyType*> | enemyTypes | N/A |
| string | bg | N/A |

**Return Type:**  (N/A)


### Area::diagonalTileFinder
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | A renderwindow is used to create the diagonally flipped textures |
| const Layer::Ptr& | layer | The layer with tiles |

**Return Type:** void (N/A)


### Area::getIndexForID
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int& | ID | N/A |

**Return Type:** int (N/A)


### Area::renderLayer
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | N/A |
| const Layer::Ptr& | layer | N/A |
| IntRect | intrect | N/A |

**Return Type:** void (N/A)


### Area::subRender
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const Layer::Ptr& | layer | N/A |
| RenderWindow& | window | N/A |
| IntRect | rect | N/A |

**Return Type:** void (N/A)


### Area::render
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | N/A |
| Player* | player | N/A |
| World* | world | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** void (N/A)


### Area::placePlayer
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Player* | player | N/A |

**Return Type:** void (N/A)


### Area::collision
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | N/A |
| Collideable* | player | N/A |

**Return Type:** void (N/A)


## src/BattleOptions.cpp
### BattleOptions::BattleOptions
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | N/A |

**Return Type:**  (N/A)


### BattleOptions::makeMaxWidth
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Entity*& | object | N/A |
| double& | scalingSize | N/A |
| SDL_Texture* | texture | N/A |

**Return Type:** void (N/A)


### BattleOptions::customDraw
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |

**Return Type:** void (N/A)


### BattleOptions::selectionLimiting
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** void (N/A)


### boDecrement
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### boIncrement
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### boUp
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### boDown
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### boSelect
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### boMainOptionSelect
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


## src/Buff.cpp
### Buff::Buff
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | l | N/A |
| int | t | N/A |
| BuffType b) : | bufftype(b | N/A |

**Return Type:**  (N/A)


### Buff::Buff
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const Buff &t) : | bufftype(t.bufftype | N/A |

**Return Type:**  (N/A)


### Buff::infoUpdate
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** void (N/A)


### Buff::changeBuff
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Buff | b | N/A |
| double | (\*op)(double | N/A |
|  | ouble) | N/A |

**Return Type:** void (N/A)


### Add
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| double | a | N/A |
| double | b | N/A |

**Return Type:** double (N/A)


### Subtract
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| double | a | N/A |
| double | b | N/A |

**Return Type:** double (N/A)


### Buff::merge
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Buff | b | N/A |

**Return Type:** void (N/A)


### Buff::remove
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Buff | b | N/A |

**Return Type:** void (N/A)


### Buff::effect
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Fightable | character | N/A |

**Return Type:** void (N/A)


### Buff::turnOver
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Fightable | f | N/A |

**Return Type:** void (N/A)


## src/BuffMove.cpp
### BuffMove::BuffMove
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| string | n | N/A |
| float | d | N/A |
| int | m | N/A |
| bool | p | N/A |
| bool | se | N/A |
| int | a | N/A |
| vector<Tag> | t | N/A |
| vector<KeyFrame> | k | N/A |
|  | ector<pair<int | N/A |
| NoteType>> | sn | N/A |
| vector<Buff> | ta | N/A |
| bool | tet | N/A |
| int h) : | Move(n | N/A |
|  |  | N/A |
|  |  | N/A |
|  |  | N/A |
|  | e | N/A |
|  |  | N/A |
|  |  | N/A |
|  |  | N/A |
|  | n | N/A |
|  | et | N/A |
|  |  | N/A |

**Return Type:**  (N/A)


## src/BuffType.cpp
### BuffType::BuffType
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| string | n | N/A |
| string | d | N/A |
| bool | b | N/A |

**Return Type:**  (N/A)


### BuffType::effect
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | level | N/A |
| Fightable | c | N/A |

**Return Type:** void (N/A)


### BuffType::operator==
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| BuffType& | bt | N/A |

**Return Type:** bool (N/A)


## src/Collideable.cpp
### Collideable::draw
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| World* | world | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** bool (N/A)


### Collideable::getHitbox
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** SDL_Rect (N/A)


### Collideable::getPoints
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** vector<Vector2f> (N/A)


## src/ControlsConfig.cpp
## src/Enemy.cpp
### Enemy::Enemy
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| EnemyType* | e | N/A |
| int | x | N/A |
| int | y | N/A |
| Player* p) : | et(e) | N/A |
|  | omex(x) | N/A |
|  | omey(y) | N/A |
|  | layer(p | N/A |

**Return Type:**  (N/A)


### Enemy::draw
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| World* | world | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** bool (N/A)


### Enemy::changeSpriteSheet
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| string | newSheet | N/A |

**Return Type:** void (N/A)


### Enemy::battle
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| Fightable* | turn | N/A |
| vector<GameObject*>& | battleEntities | N/A |

**Return Type:** void (N/A)


## src/EnemyType.cpp
### EnemyType::EnemyType
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| string | n | N/A |
| Stats | s | N/A |
| vector<Move*> | m | N/A |
| float | ms | N/A |
| float | ps | N/A |
| float | mas | N/A |
| float | pas | N/A |
| MOVEMENT_TYPE | movementtype | N/A |
| int | sr | N/A |
| int | hr | N/A |
| bool | h | N/A |
| string | p | N/A |
| int | wid | N/A |
| int | hei | N/A |

**Return Type:**  (N/A)


## src/Entity.cpp
### Entity::~Entity
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**  (N/A)


### Entity::Entity
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| ) : | x(0) | N/A |
|  | (0 | N/A |

**Return Type:**  (N/A)


### Entity::Entity
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| float | px | N/A |
| float | py | N/A |
| SDL_Texture* | ptexture | N/A |
| int | pw | N/A |
| int ph) : | x(px) | N/A |
|  | (py) | N/A |
|  | idth(pw) | N/A |
|  | eight(ph) | N/A |
|  | how_width(pw) | N/A |
|  | how_height(ph | N/A |

**Return Type:**  (N/A)


### Entity::Entity
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| float | px | N/A |
| float | py | N/A |
| SDL_Texture* ptexture) : | x(px) | N/A |
|  | (py | N/A |

**Return Type:**  (N/A)


### Entity::setTexture
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| SDL_Texture* | ptexture | N/A |

**Return Type:** void (N/A)


### Entity::Entity
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const Entity& | e | N/A |

**Return Type:**  (N/A)


### Entity::fullPicSize
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** void (N/A)


### Entity::setRect
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** void (N/A)


### Entity::getsize
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** SDL_Point (N/A)


### SDL_QueryTexture
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | exture.get() | N/A |
|  | ULL | N/A |
|  | ULL | N/A |
|  | size.x | N/A |
|  | size.y | N/A |

**Return Type:**     (N/A)


### Entity::getRect
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** SDL_Rect (N/A)


### Entity::distance
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Entity* | e | N/A |

**Return Type:** float (N/A)


### Entity::angleBetween
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Entity* | e | N/A |

**Return Type:** float (N/A)


### Entity::customDraw
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |

**Return Type:** void (N/A)


## src/Fightable.cpp
### Fightable::Fightable
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**  (N/A)


### Fightable::battle
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| Fightable* | turn | N/A |
| vector<GameObject*>& | battleEntities | N/A |

**Return Type:** void (N/A)


## src/FreeFuncs.cpp
### tmx::decompress
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const char* | source | N/A |
| std::vector<unsigned char>& | dest | N/A |
| std::size_t | inSize | N/A |
| std::size_t | expectedSize | N/A |

**Return Type:** bool (N/A)


### LOG
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Input string is | empty | N/A |
| decompression | failed." | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### static_cast<int>
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | xpectedSize | N/A |

**Return Type:**     int currentSize = (N/A)


### byteArray
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| expectedSize / sizeof(unsigned | char) | N/A |

**Return Type:**     std::vector<unsigned char> (N/A)


### int>
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | nSize | N/A |

**Return Type:**     stream.avail_in = static_cast<unsigned (N/A)


### int>
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | xpectedSize | N/A |

**Return Type:**     stream.avail_out = static_cast<unsigned (N/A)


### LOG
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "inflate init | failed" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### inflate
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | stream | N/A |
|  | _SYNC_FLUSH | N/A |

**Return Type:**         result = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "If using gzip or zstd compression try using zlib | instead" | N/A |
|  | ogger::Type::Info | N/A |

**Return Type:**             (N/A)


### inflateEnd
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | stream | N/A |

**Return Type:**             (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "inflate() returned " +  | std::to_string(result) | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**             (N/A)


### newArray
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| currentSize / sizeof(unsigned | char) | N/A |

**Return Type:**             std::vector<unsigned char> (N/A)


### std::memcpy
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ewArray.data() | N/A |
|  | yteArray.data() | N/A |
| currentSize / | 2 | N/A |

**Return Type:**             (N/A)


### std::move
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ewArray | N/A |

**Return Type:**             byteArray = (N/A)


### LOG
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "stream.avail_in is | 0" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### LOG
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "zlib decompression | failed." | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### inflateEnd
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | stream | N/A |

**Return Type:**     (N/A)


### newArray
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| outSize / sizeof(unsigned | char) | N/A |

**Return Type:**     std::vector<unsigned char> (N/A)


### std::memcpy
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ewArray.data() | N/A |
|  | yteArray.data() | N/A |
|  | utSize | N/A |

**Return Type:**     (N/A)


### std::move
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ewArray | N/A |

**Return Type:**     byteArray = (N/A)


### dest.insert
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | est.begin() | N/A |
|  | yteArray.begin() | N/A |
|  | yteArray.end() | N/A |

**Return Type:**     (N/A)


## src/GameObject.cpp
### GameObject::GameObject
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**  (N/A)


### GameObject::GameObject
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| float | px | N/A |
| float | py | N/A |
| SDL_Texture* | ptexture | N/A |
| int | pw | N/A |
| int ph) : | Entity(px | N/A |
|  | y | N/A |
|  | texture | N/A |
|  | w | N/A |
|  | h | N/A |

**Return Type:**  (N/A)


### GameObject::draw
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| World* | world | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** bool (N/A)


### GameObject::changeSpriteSheet
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| string | newSheet | N/A |

**Return Type:** void (N/A)


### GameObject::createObject
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** GameObject* (N/A)


## src/HealthBar.cpp
### HealthBar::HealthBar
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| int | x | N/A |
| int | y | N/A |
| int | w | N/A |
| int | h | N/A |

**Return Type:**  (N/A)


### HealthBar::~HealthBar
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**  (N/A)


### HealthBar::represent
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| Fightable* | fighter | N/A |

**Return Type:** void (N/A)


## src/ImageLayer.cpp
### ImageLayer::ImageLayer
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const std::string& | workingDir | N/A |

**Return Type:**  (N/A)


### ImageLayer::parse
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |
|  | ap* | N/A |

**Return Type:** void (N/A)


### node.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     std::string attribName = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Node not an image | layer | N/A |
| node | skipped" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### setName
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("name").as_string() | N/A |

**Return Type:**     (N/A)


### setOpacity
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("opacity").as_float(1.f) | N/A |

**Return Type:**     (N/A)


### setVisible
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("visible").as_bool(true) | N/A |

**Return Type:**     (N/A)


### setOffset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("offsetx").as_int() | N/A |
|  | ode.attribute("offsety").as_int() | N/A |

**Return Type:**     (N/A)


### setSize
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("width").as_uint() | N/A |
|  | ode.attribute("height").as_uint() | N/A |

**Return Type:**     (N/A)


### child.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         attribName = (N/A)


### child.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | source").as_string( | N/A |

**Return Type:**             attribName = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Image Layer has missing source | property" | N/A |
|  | ogger::Type::Warning | N/A |

**Return Type:**                 (N/A)


### child.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | width").as_uint( | N/A |

**Return Type:**             	m_imageSize.x = (N/A)


### child.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | height").as_uint( | N/A |

**Return Type:**             	m_imageSize.y = (N/A)


### resolveFilePath
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ttribName | N/A |
|  | _workingDir | N/A |

**Return Type:**             m_filePath = (N/A)


### child.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | trans").as_string( | N/A |

**Return Type:**                 attribName = (N/A)


### colourFromString
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ttribName | N/A |

**Return Type:**                 m_transparencyColour = (N/A)


### addProperty
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  |  | N/A |

**Return Type:**                 (N/A)


## src/KeyFrame.cpp
### KeyFrame::KeyFrame
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | f | N/A |
| string | a | N/A |
| int | ro | N/A |
| int | xTemp | N/A |
| int | yTemp | N/A |
| ReferenceFrame | r | N/A |
| Interpolation | i | N/A |
| bool | d | N/A |
| int fd) : | frame(f) | N/A |
|  | nimation(a) | N/A |
|  | ow(ro) | N/A |
|  | (xTemp) | N/A |
|  | (yTemp) | N/A |
|  | f(r) | N/A |
|  | nter(i) | N/A |
|  | amage(d) | N/A |
|  | ramedelay(fd | N/A |

**Return Type:**  (N/A)


### KeyFrame::applyKeyframe
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Fightable* | attacker | N/A |
| KeyFrame& | previous | N/A |
| int | curFrame | N/A |
| Fightable* | defender | N/A |
| bool | reverse | N/A |

**Return Type:** void (N/A)


### KeyFrame::base
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Fightable* | attacker | N/A |
| Fightable* | defender | N/A |
| bool | reverse | N/A |

**Return Type:** pair<int, int> (N/A)


## src/LayerGroup.cpp
### LayerGroup::LayerGroup
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const std::string& | workingDir | N/A |
| const Vector2u& | tileCount | N/A |

**Return Type:**  (N/A)


### m_workingDir
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | orkingDir | N/A |

**Return Type:**     : (N/A)


### m_tileCount
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ileCount | N/A |

**Return Type:**     (N/A)


### LayerGroup::parse
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |
| Map* | map | N/A |

**Return Type:** void (N/A)


### assert
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ap | N/A |

**Return Type:**     (N/A)


### node.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     std::string attribString = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Node was not a group | layer | N/A |
| node will be | skipped." | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### setName
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("name").as_string() | N/A |

**Return Type:**     (N/A)


### setOpacity
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("opacity").as_float(1.f) | N/A |

**Return Type:**     (N/A)


### setVisible
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("visible").as_bool(true) | N/A |

**Return Type:**     (N/A)


### setOffset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("offsetx").as_int() | N/A |
|  | ode.attribute("offsety").as_int() | N/A |

**Return Type:**     (N/A)


### setSize
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("width").as_uint() | N/A |
|  | ode.attribute("height").as_uint() | N/A |

**Return Type:**     (N/A)


### child.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         attribString = (N/A)


### addProperty
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  |  | N/A |

**Return Type:**                 (N/A)


### m_layers.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| std::make_unique<TileLayer>(m_tileCount.x * | m_tileCount.y) | N/A |

**Return Type:**             (N/A)


### m_layers.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ->parse(child | N/A |
|  | ap | N/A |

**Return Type:**             (N/A)


### m_layers.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | td::make_unique<ObjectGroup>() | N/A |

**Return Type:**             (N/A)


### m_layers.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ->parse(child | N/A |
|  | ap | N/A |

**Return Type:**             (N/A)


### m_layers.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | td::make_unique<ImageLayer>(m_workingDir) | N/A |

**Return Type:**             (N/A)


### m_layers.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ->parse(child | N/A |
|  | ap | N/A |

**Return Type:**             (N/A)


### m_layers.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | td::make_unique<LayerGroup>(m_workingDir | N/A |
|  | _tileCount) | N/A |

**Return Type:**             (N/A)


### m_layers.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ->parse(child | N/A |
|  | ap | N/A |

**Return Type:**             (N/A)


### LOG
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Unidentified name " + attribString + ": node | skipped" | N/A |
|  | ogger::Type::Warning | N/A |

**Return Type:**             (N/A)


## src/main.cpp
### atanLookup
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | vv | Vector of RenderWindow in index 0 and float that you are looking for in index 1 |

**Return Type:** float (s atan of vv[1])


### flippedIndex
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | num | N/A |
|  | ector<pair<int | N/A |
| int>>& | degree45 | N/A |
| int subtract = | 0 | N/A |

**Return Type:** inline pair<int, int> (N/A)


### inRange
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | n | N/A |
| int | s | N/A |
| int | l | N/A |

**Return Type:** inline bool (N/A)


### operator+
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const | pair<int | N/A |
| int>& | a | N/A |
| const | pair<int | N/A |
| int>& | b | N/A |

**Return Type:** pair<int, int> (N/A)


### operator<<
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| ostream& | os | N/A |
| const KeyFrame& | obj | N/A |

**Return Type:** ostream& (N/A)


### spiralPerPixel
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Uint32* | pixels | N/A |
| Uint32* | newPixels | N/A |
|  | ector<pair<int | N/A |
| int>>& | degree45 | N/A |
|  | air<int | N/A |
| int>& | center | N/A |
| SDL_Rect& | texture_rect | N/A |
| int | z | N/A |
| int | r | N/A |
| SDL_PixelFormat* | format | N/A |
| int | transitionFrames | N/A |
| double | val | N/A |

**Return Type:** void (N/A)


### movementCompute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | transitionFrames | N/A |
|  | ector<pair<int | N/A |
| int>>& | degree45 | N/A |
| int | r | N/A |
| SDL_Rect& | texture_rect | N/A |

**Return Type:** double (N/A)


### blackCompute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | transitionFrames | N/A |
|  | ector<pair<int | N/A |
| int>>& | degree45 | N/A |
| int | r | N/A |
| SDL_Rect& | texture_rect | N/A |

**Return Type:** double (N/A)


### blackPerPixel
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Uint32* | pixels | N/A |
| Uint32* | newPixels | N/A |
|  | ector<pair<int | N/A |
| int>>& | degree45 | N/A |
|  | air<int | N/A |
| int>& | center | N/A |
| SDL_Rect& | texture_rect | N/A |
| int | z | N/A |
| int | r | N/A |
| SDL_PixelFormat* | format | N/A |
| int | transitionFrames | N/A |
| double | mult | N/A |

**Return Type:** void (N/A)


### circularScreenEdit
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | rstart | N/A |
| int | rend | N/A |
| SDL_Rect | texture_rect | N/A |
| int | transitionFrames | N/A |
| Uint32* | pixels | N/A |
| Uint32* | newPixels | N/A |
| int | maxRadius | N/A |
| SDL_PixelFormat* | format | N/A |
| void | (\*perPixel)(Uint32*,Uint32*,vector<pair<int | N/A |
|  | nt>>&,pair<int | N/A |
|  | nt>&,SDL_Rect&,int,int,SDL_PixelFormat*,int,double) | N/A |
| double | (\*compute)(int | N/A |
|  | ector<pair<int | N/A |
|  | nt>>& | N/A |
| int | r | N/A |
|  | DL_Rect&) | N/A |

**Return Type:** void (N/A)


### getChunks
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| string | s | N/A |

**Return Type:** map<char, Mix_Chunk*> (N/A)


### backout
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### forward
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### sortComb
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<T*>& | vec | N/A |
| int | (\*foo)(T*) | N/A |

**Return Type:** void (N/A)


### getValue
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Fightable* | f | N/A |

**Return Type:** int (N/A)


### getValue
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Enemy* | f | N/A |

**Return Type:** int (N/A)


### rhythmPress
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<RhythmNote*>* | notes | N/A |
| float* | howGoodYouDoIt | N/A |
| float | maxGoodness | N/A |
| NoteType | nt | N/A |

**Return Type:** void (N/A)


### rhythmPressUp
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### rhythmPressLeft
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### rhythmPressRight
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### rhythmPressDown
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### threadCircularApplication
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | N/A |
| Uint32*& | newPixels | N/A |
| SDL_Texture*& | window_texture | N/A |
| SDL_Surface*& | window_surface | N/A |
| int& | transitionFrames | N/A |
| SDL_Rect& | texture_rect | N/A |
| const int& | THREADS | N/A |
| int | start | N/A |
| double | mod | N/A |
| void | (\*perPixel)(Uint32*,Uint32*,vector<pair<int | N/A |
|  | nt>>&,pair<int | N/A |
|  | nt>&,SDL_Rect&,int,int,SDL_PixelFormat*,int,double) | N/A |
| double | (\*compute)(int | N/A |
|  | ector<pair<int | N/A |
|  | nt>>& | N/A |
| int | r | N/A |
|  | DL_Rect&) | N/A |

**Return Type:** inline SDL_Texture* (N/A)


### main
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | argc | N/A |
| char | *argv[] | N/A |

**Return Type:** int (N/A)


## src/Map.cpp
### Map::Map
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**  (N/A)


### Map::load
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const std::string& | path | N/A |

**Return Type:** bool (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     (N/A)


### doc.load_file
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ath.c_str() | N/A |

**Return Type:**     auto result = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Failed opening " + | path | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Reason: " + | std::string(result.description()) | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### std::replace
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | _workingDirectory.begin() | N/A |
|  | _workingDirectory.end() | N/A |
|  | \\' | N/A |
|  | /' | N/A |

**Return Type:**     (N/A)


### getFilePath
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | _workingDirectory | N/A |

**Return Type:**     m_workingDirectory = (N/A)


### m_workingDirectory.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| ) == | '/' | N/A |

**Return Type:**         (N/A)


### m_workingDirectory.pop_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         (N/A)


### doc.child
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | map" | N/A |

**Return Type:**     auto mapNode = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Failed opening map: " + path + | " | N/A |
| no map node | found" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         return (N/A)


### parseMapNode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | apNode | N/A |

**Return Type:**     return (N/A)


### Map::loadFromString
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const std::string& | data | N/A |
| const std::string& | workingDir | N/A |

**Return Type:** bool (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     (N/A)


### doc.load_string
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ata.c_str() | N/A |

**Return Type:**     auto result = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Failed opening | map" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Reason: " + | std::string(result.description()) | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### std::replace
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | _workingDirectory.begin() | N/A |
|  | _workingDirectory.end() | N/A |
|  | \\' | N/A |
|  | /' | N/A |

**Return Type:**     (N/A)


### getFilePath
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | _workingDirectory | N/A |

**Return Type:**     m_workingDirectory = (N/A)


### m_workingDirectory.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| ) == | '/' | N/A |

**Return Type:**         (N/A)


### m_workingDirectory.pop_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         (N/A)


### doc.child
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | map" | N/A |

**Return Type:**     auto mapNode = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Failed opening map: no map node | found" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         return (N/A)


### parseMapNode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | apNode | N/A |

**Return Type:**     return (N/A)


### Map::parseMapNode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | mapNode | N/A |

**Return Type:** bool (N/A)


### mapNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | version").as_string( | N/A |

**Return Type:**     std::string attribString = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Invalid map version | value | N/A |
| map not | loaded." | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         return (N/A)


### STOI
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ttribString.substr(0 | N/A |
|  | ointPos) | N/A |

**Return Type:**     m_version.upper = (N/A)


### STOI
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| attribString.substr(pointPos + | 1) | N/A |

**Return Type:**     m_version.lower = (N/A)


### mapNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | orientation").as_string( | N/A |

**Return Type:**     attribString = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Missing map orientation | attribute | N/A |
| map not | loaded." | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         return (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| attribString + " format maps aren't supported | yet | N/A |
| sorry! Map not | loaded" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         return (N/A)


### mapNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | renderorder").as_string( | N/A |

**Return Type:**     attribString = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| attribString + ": invalid render order. Map not | loaded." | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**             (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**             return (N/A)


### mapNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | infinite").as_int( | N/A |

**Return Type:**         m_infinite = (N/A)


### mapNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | width").as_int( | N/A |

**Return Type:**     unsigned width = (N/A)


### mapNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | height").as_int( | N/A |

**Return Type:**     unsigned height = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Invalid map tile | count | N/A |
| map not | loaded" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         return (N/A)


### mapNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | tilewidth").as_int( | N/A |

**Return Type:**     width = (N/A)


### mapNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | tileheight").as_int( | N/A |

**Return Type:**     height = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Invalid tile | size | N/A |
| map not | loaded" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         return (N/A)


### mapNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | hexsidelength").as_float( | N/A |

**Return Type:**     m_hexSideLength = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Invalid he side length | found | N/A |
| map not | loaded" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         return (N/A)


### mapNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | staggeraxis").as_string( | N/A |

**Return Type:**     attribString = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Map missing stagger axis property. Map not | loaded." | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         return (N/A)


### mapNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | staggerindex").as_string( | N/A |

**Return Type:**     attribString = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Map missing stagger index property. Map not | loaded." | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         return (N/A)


### mapNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | backgroundcolor").as_string( | N/A |

**Return Type:**     attribString = (N/A)


### colourFromString
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ttribString | N/A |

**Return Type:**         m_backgroundColour = (N/A)


### node.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         std::string name = (N/A)


### m_tilesets.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | _workingDirectory | N/A |

**Return Type:**             (N/A)


### m_tilesets.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | .parse(node | N/A |
|  | his | N/A |

**Return Type:**             (N/A)


### m_layers.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| std::make_unique<TileLayer>(m_tileCount.x * | m_tileCount.y) | N/A |

**Return Type:**             (N/A)


### m_layers.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ->parse(node | N/A |

**Return Type:**             (N/A)


### m_layers.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | td::make_unique<ObjectGroup>() | N/A |

**Return Type:**             (N/A)


### m_layers.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ->parse(node | N/A |
|  | his | N/A |

**Return Type:**             (N/A)


### m_layers.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | td::make_unique<ImageLayer>(m_workingDirectory) | N/A |

**Return Type:**             (N/A)


### m_layers.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ->parse(node | N/A |
|  | his | N/A |

**Return Type:**             (N/A)


### node.children
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**             const auto& children = (N/A)


### m_properties.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**                 (N/A)


### m_properties.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | .parse(child | N/A |

**Return Type:**                 (N/A)


### m_layers.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | td::make_unique<LayerGroup>(m_workingDirectory | N/A |
|  | _tileCount) | N/A |

**Return Type:**             (N/A)


### m_layers.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ->parse(node | N/A |
|  | his | N/A |

**Return Type:**             (N/A)


### LOG
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Unidentified name " + name + ": node | skipped" | N/A |
|  | ogger::Type::Warning | N/A |

**Return Type:**             (N/A)


### for
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const auto& ts : | m_tilesets | N/A |

**Return Type:**     (N/A)


### for
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const auto& tile : | ts.getTiles() | N/A |

**Return Type:**         (N/A)


### ts.getFirstGID
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**                 m_animTiles[tile.ID + (N/A)


### Map::reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** bool (N/A)


### m_tilesets.clear
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     (N/A)


### m_layers.clear
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     (N/A)


### m_properties.clear
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     (N/A)


### m_templateObjects.clear
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     (N/A)


### m_templateTilesets.clear
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     (N/A)


## src/Move.cpp
### Move::Move
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| string | n | N/A |
| float | d | N/A |
| int | m | N/A |
| bool | p | N/A |
| bool | se | N/A |
| int | a | N/A |
| vector<Tag> | t | N/A |
| vector<KeyFrame> | k | N/A |
|  | ector<pair<int | N/A |
| NoteType>> | sn | N/A |
| bool | tet | N/A |
| int h) : | ap(a) | N/A |
|  | ame(n) | N/A |
|  | hysical(p) | N/A |
|  | amage(d) | N/A |
|  | ana(m) | N/A |
|  | electEnemy(se) | N/A |
|  | ags(t) | N/A |
|  | nimation(k) | N/A |
|  | argetEnemyTeam(tet) | N/A |
|  | its(h) | N/A |
|  | tingerNotes(sn | N/A |

**Return Type:**  (N/A)


### Move::getHitting
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Fightable* | attacker | N/A |
| Fightable* | defender | N/A |

**Return Type:** bool (N/A)


### Move::getCrit
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Fightable* | attacker | N/A |

**Return Type:** bool (N/A)


### Move::dealDamage
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| Fightable* | attacker | N/A |
| Fightable* | defender | N/A |
| vector<GameObject*>& | battleEntities | N/A |
| bool | hitting | N/A |
| bool | crit | N/A |
| float | howGoodYouDoIt | N/A |

**Return Type:** void (N/A)


## src/Object.cpp
### Object::Object
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**  (N/A)


### Object::parse
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |
| Map* | map | N/A |

**Return Type:** void (N/A)


### node.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     std::string attribString = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "This not an Object | node | N/A |
| parsing | skipped." | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | id").as_int( | N/A |

**Return Type:**     m_UID = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | name").as_string( | N/A |

**Return Type:**     m_name = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | type").as_string( | N/A |

**Return Type:**     m_class = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | class").as_string( | N/A |

**Return Type:**         m_class = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | x").as_float( | N/A |

**Return Type:**     m_position.x = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | y").as_float( | N/A |

**Return Type:**     m_position.y = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | width").as_float( | N/A |

**Return Type:**     m_AABB.width = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | height").as_float( | N/A |

**Return Type:**     m_AABB.height = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | rotation").as_float( | N/A |

**Return Type:**     m_rotation = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | visible").as_bool(true | N/A |

**Return Type:**     m_visible = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | gid").as_uint( | N/A |

**Return Type:**     m_tileID = (N/A)


### child.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         attribString = (N/A)


### m_properties.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**                 (N/A)


### m_properties.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | .parse(p | N/A |

**Return Type:**                 (N/A)


### parsePoints
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | hild | N/A |

**Return Type:**             (N/A)


### parsePoints
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | hild | N/A |

**Return Type:**             (N/A)


### parseText
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | hild | N/A |

**Return Type:**             (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | template").as_string( | N/A |

**Return Type:**     std::string templateStr = (N/A)


### parseTemplate
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | emplateStr | N/A |
|  | ap | N/A |

**Return Type:**         (N/A)


### Object::parsePoints
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |

**Return Type:** void (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | points").as_string( | N/A |

**Return Type:**         std::string pointlist = (N/A)


### stream
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ointlist | N/A |

**Return Type:**         std::stringstream (N/A)


### points.push_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ointstring | N/A |

**Return Type:**             (N/A)


### coordstream
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | oints[i] | N/A |

**Return Type:**             std::stringstream (N/A)


### coords.push_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  |  | N/A |

**Return Type:**                 (N/A)


### coordstream.ignore
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**                     (N/A)


### m_points.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | oords[0] | N/A |
|  | oords[1] | N/A |

**Return Type:**             (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Points for polygon or polyline object are | missing" | N/A |
|  | ogger::Type::Warning | N/A |

**Return Type:**         (N/A)


### Object::parseText
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |

**Return Type:** void (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | bold").as_bool(false | N/A |

**Return Type:**     m_textData.bold = (N/A)


### colourFromString
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("color").as_string("#FFFFFFFF") | N/A |

**Return Type:**     m_textData.colour = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | fontfamily").as_string( | N/A |

**Return Type:**     m_textData.fontFamily = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | italic").as_bool(false | N/A |

**Return Type:**     m_textData.italic = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | kerning").as_bool(true | N/A |

**Return Type:**     m_textData.kerning = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | pixelsize").as_uint(16 | N/A |

**Return Type:**     m_textData.pixelSize = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | strikeout").as_bool(false | N/A |

**Return Type:**     m_textData.strikethough = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | underline").as_bool(false | N/A |

**Return Type:**     m_textData.underline = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | wrap").as_bool(false | N/A |

**Return Type:**     m_textData.wrap = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | halign").as_string("left" | N/A |

**Return Type:**     std::string alignment = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | valign").as_string("top" | N/A |

**Return Type:**     alignment = (N/A)


### node.text
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | .as_string( | N/A |

**Return Type:**     m_textData.content = (N/A)


### Object::parseTemplate
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const std::string& | path | N/A |
| Map* | map | N/A |

**Return Type:** void (N/A)


### assert
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ap | N/A |

**Return Type:**     (N/A)


### map->getTemplateObjects
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     auto& templateObjects = (N/A)


### map->getTemplateTilesets
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     auto& templateTilesets = (N/A)


### map->getWorkingDirectory
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         auto templatePath = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Failed opening template file " + | path | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**             (N/A)


### doc.child
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | template" | N/A |

**Return Type:**         auto templateNode = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Template node missing from " + | path | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**             (N/A)


### templateNode.child
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | tileset" | N/A |

**Return Type:**         auto tileset = (N/A)


### tileset.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | source").as_string( | N/A |

**Return Type:**             tilesetName = (N/A)


### templateTilesets.count
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| tilesetName) == | 0 | N/A |

**Return Type:**                 (N/A)


### templateTilesets.insert
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | td::make_pair(tilesetName | N/A |
|  | ileset(map->getWorkingDirectory())) | N/A |

**Return Type:**                 (N/A)


### templateTilesets.at
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ilesetName).parse(tileset | N/A |
|  | ap | N/A |

**Return Type:**                 (N/A)


### templateNode.child
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | object" | N/A |

**Return Type:**         auto obj = (N/A)


### templateObjects.insert
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | td::make_pair(path | N/A |
|  | bject()) | N/A |

**Return Type:**             (N/A)


### templateObjects[path].parse
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | bj | N/A |
|  | ullptr | N/A |

**Return Type:**             (N/A)


### std::find_if
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | _properties.begin() | N/A |
|  | _properties.end( | N/A |

**Return Type:**             auto result = (N/A)


### [&p]
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const Property& | a | N/A |

**Return Type:**                 (N/A)


### a.getName
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| ) == | p.getName( | N/A |

**Return Type:**                     return (N/A)


### m_properties.push_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  |  | N/A |

**Return Type:**                 (N/A)


## src/ObjectGroup.cpp
### ObjectGroup::ObjectGroup
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**  (N/A)


### ObjectGroup::parse
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |
| Map* | map | N/A |

**Return Type:** void (N/A)


### assert
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ap | N/A |

**Return Type:**     (N/A)


### node.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     std::string attribString = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Node was not an object | group | N/A |
| node will be | skipped." | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### setName
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("name").as_string() | N/A |

**Return Type:**     (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | color").as_string( | N/A |

**Return Type:**     attribString = (N/A)


### colourFromString
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ttribString | N/A |

**Return Type:**         m_colour = (N/A)


### setOpacity
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("opacity").as_float(1.f) | N/A |

**Return Type:**     (N/A)


### setVisible
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("visible").as_bool(true) | N/A |

**Return Type:**     (N/A)


### setOffset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("offsetx").as_int() | N/A |
|  | ode.attribute("offsety").as_int() | N/A |

**Return Type:**     (N/A)


### setSize
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("width").as_uint() | N/A |
|  | ode.attribute("height").as_uint() | N/A |

**Return Type:**     (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | draworder").as_string( | N/A |

**Return Type:**     attribString = (N/A)


### child.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         attribString = (N/A)


### m_properties.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**                 (N/A)


### m_properties.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | .parse(p | N/A |

**Return Type:**                 (N/A)


### m_objects.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**             (N/A)


### m_objects.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | .parse(child | N/A |
|  | ap | N/A |

**Return Type:**             (N/A)


## src/ObjectTypes.cpp
### ObjectTypes::load
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const std::string | &path | N/A |

**Return Type:** bool (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     (N/A)


### doc.load_file
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ath.c_str() | N/A |

**Return Type:**     auto result = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Failed opening " + | path | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Reason: " + | std::string(result.description()) | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### std::replace
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | _workingDirectory.begin() | N/A |
|  | _workingDirectory.end() | N/A |
|  | \\' | N/A |
|  | /' | N/A |

**Return Type:**     (N/A)


### getFilePath
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | _workingDirectory | N/A |

**Return Type:**     m_workingDirectory = (N/A)


### m_workingDirectory.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| ) == | '/' | N/A |

**Return Type:**         (N/A)


### m_workingDirectory.pop_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         (N/A)


### doc.child
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | objecttypes" | N/A |

**Return Type:**     auto node = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Failed opening object types: " + path + | " | N/A |
| no objecttype node | found" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         return (N/A)


### parseObjectTypesNode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode | N/A |

**Return Type:**     return (N/A)


### ObjectTypes::loadFromString
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const std::string | &data | N/A |
| const std::string | &workingDir | N/A |

**Return Type:** bool (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     (N/A)


### doc.load_string
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ata.c_str() | N/A |

**Return Type:**     auto result = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Failed opening object | types" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Reason: " + | std::string(result.description()) | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### std::replace
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | _workingDirectory.begin() | N/A |
|  | _workingDirectory.end() | N/A |
|  | \\' | N/A |
|  | /' | N/A |

**Return Type:**     (N/A)


### getFilePath
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | _workingDirectory | N/A |

**Return Type:**     m_workingDirectory = (N/A)


### m_workingDirectory.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| ) == | '/' | N/A |

**Return Type:**         (N/A)


### m_workingDirectory.pop_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         (N/A)


### doc.child
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | objecttypes" | N/A |

**Return Type:**     auto node = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Failed object types: no objecttypes node | found" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         return (N/A)


### parseObjectTypesNode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode | N/A |

**Return Type:**     return (N/A)


### ObjectTypes::parseObjectTypesNode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node | &node | N/A |

**Return Type:** bool (N/A)


### for
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const auto& child : | node.children() | N/A |

**Return Type:**     (N/A)


### child.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         std::string attribString = (N/A)


### child.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | name").as_string( | N/A |

**Return Type:**             type.name = (N/A)


### colourFromString
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | hild.attribute("color").as_string("#FFFFFFFF") | N/A |

**Return Type:**             type.colour = (N/A)


### prop.parse
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  |  | N/A |
|  | rue | N/A |

**Return Type:**                 (N/A)


### type.properties.push_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | rop | N/A |

**Return Type:**                 (N/A)


### m_types.push_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ype | N/A |

**Return Type:**             (N/A)


### LOG
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Unidentified name " + attribString + ": node | skipped" | N/A |
|  | ogger::Type::Warning | N/A |

**Return Type:**             (N/A)


### ObjectTypes::reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** bool (N/A)


### m_workingDirectory.clear
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     (N/A)


### m_types.clear
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     (N/A)


## src/PartyMember.cpp
### PartyMember::battle
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| Fightable* | turn | N/A |
| vector<GameObject*>& | battleEntities | N/A |

**Return Type:** void (N/A)


### PartyMember::doAttack
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| Fightable* | enemy | N/A |
| vector<GameObject*>& | battleEntities | N/A |

**Return Type:** void (N/A)


## src/Player.cpp
### Player::Player
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| vector<Move*> | m | N/A |

**Return Type:**  (N/A)


### Player::draw
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| World* | world | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** bool (N/A)


### Player::changeDirection
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Input& | input | N/A |

**Return Type:** void (N/A)


## src/Property.cpp
### Property::Property
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**  (N/A)


### m_type
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ype::Undef | N/A |

**Return Type:**     : (N/A)


### Property::fromBoolean
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| bool | value | N/A |

**Return Type:** Property (N/A)


### Property::fromFloat
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| float | value | N/A |

**Return Type:** Property (N/A)


### Property::fromInt
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | value | N/A |

**Return Type:** Property (N/A)


### Property::fromString
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const std::string& | value | N/A |

**Return Type:** Property (N/A)


### Property::fromColour
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const Colour& | value | N/A |

**Return Type:** Property (N/A)


### Property::fromFile
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const std::string& | value | N/A |

**Return Type:** Property (N/A)


### Property::fromObject
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | value | N/A |

**Return Type:** Property (N/A)


### Property::parse
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |
| bool | isObjectTypes | N/A |

**Return Type:** void (N/A)


### node.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     std::string attribData = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Node was not a valid | property | N/A |
| node will be | skipped" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | name").as_string( | N/A |

**Return Type:**     m_name = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | type").as_string("string" | N/A |

**Return Type:**     attribData = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | alueAttribute).as_string("false" | N/A |

**Return Type:**         attribData = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | alueAttribute).as_int(0 | N/A |

**Return Type:**         m_intValue = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | alueAttribute).as_float(0.f | N/A |

**Return Type:**         m_floatValue = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | alueAttribute).as_string( | N/A |

**Return Type:**         m_stringValue = (N/A)


### if
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | _stringValue.empty() | N/A |

**Return Type:**         (N/A)


### node.child_value
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**             m_stringValue = (N/A)


### colourFromString
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute(valueAttribute).as_string("#FFFFFFFF") | N/A |

**Return Type:**         m_colourValue = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | alueAttribute).as_string( | N/A |

**Return Type:**         m_stringValue = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | alueAttribute).as_int(0 | N/A |

**Return Type:**         m_intValue = (N/A)


## src/RenderWindow.cpp
### RenderWindow::RenderWindow
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const char* title) : | window(NULL) | N/A |
|  | enderer(NULL | N/A |

**Return Type:**  (N/A)


### RenderWindow::resizeWindow
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** void (N/A)


### RenderWindow::cleanUp
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** void (N/A)


### RenderWindow::loadTexture
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const char* | filePath | N/A |

**Return Type:** SDL_Texture* (N/A)


### RenderWindow::clear
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** void (N/A)


### RenderWindow::setColor
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | r | N/A |
| int | g | N/A |
| int | b | N/A |
| int | a | N/A |

**Return Type:** void (N/A)


### RenderWindow::drawLine
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | x1 | N/A |
| int | y1 | N/A |
| int | x2 | N/A |
| int | y2 | N/A |
| bool | stationary | N/A |

**Return Type:** void (N/A)


### RenderWindow::getDestRect
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Entity* | entity | N/A |
| bool | stationary | N/A |

**Return Type:** SDL_Rect (N/A)


### RenderWindow::scaleDestRect
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| SDL_Rect& | dest | N/A |

**Return Type:** void (N/A)


### RenderWindow::render
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Entity* | entity | N/A |
| bool | stationary | N/A |
| int | centerx | N/A |
| int | centery | N/A |

**Return Type:** void (N/A)


### RenderWindow::display
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** void (N/A)


### RenderWindow::drawCircle
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | x | N/A |
| int | y | N/A |
| int | radius | N/A |

**Return Type:** void (N/A)


### RenderWindow::getTextSurface
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| string | text | N/A |
| unsigned char | r | N/A |
| unsigned char | g | N/A |
| unsigned char | b | N/A |
| unsigned char | a | N/A |

**Return Type:** SDL_Surface* (N/A)


### SDL_GetError
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** //	cout << (N/A)


### TTF_GetError
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** //	cout << (N/A)


### RenderWindow::drawScaledTextInBox
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| string | text | N/A |
| unsigned char | r | N/A |
| unsigned char | g | N/A |
| unsigned char | b | N/A |
| unsigned char | a | N/A |
| int | x | N/A |
| int | y | N/A |
| int | w | N/A |
| int | h | N/A |
| bool | centered | N/A |

**Return Type:** void (N/A)


### RenderWindow::textRect
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| SDL_Surface* | surfaceMessage | N/A |
| SDL_Texture* | Message | N/A |
| SDL_Rect | Message_rect | N/A |

**Return Type:** void (N/A)


### RenderWindow::drawText
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| string | text | N/A |
| unsigned char | r | N/A |
| unsigned char | g | N/A |
| unsigned char | b | N/A |
| unsigned char | a | N/A |
| int | x | N/A |
| int | y | N/A |
| int | w | N/A |
| int | h | N/A |

**Return Type:** void (N/A)


### RenderWindow::getAreaTexture
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| SDL_Rect& | rect | N/A |
| SDL_Texture* | source | N/A |

**Return Type:** SDL_Texture* (N/A)


## src/RhythmNote.cpp
### RhythmNote::RhythmNote
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
|  | air<int | N/A |
| NoteType> | note | N/A |
| chrono::steady_clock::time_point* | s | N/A |

**Return Type:**  (N/A)


### RhythmNote::draw
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| World* | world | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** bool (N/A)


## src/Selector.cpp
### Selector::Selector
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | Window used to load the selector texture |

**Return Type:**  ( Selector)


### Selector::render
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** void (N/A)


### Selector::getSelected
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | Window used to get the teams |

**Return Type:** Fightable* ( Fighter that is selected)


### sDecrement
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### sIncrement
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### sEnter
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### sParty
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### sEnemy
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


## src/SpawnZone.cpp
### SpawnZone::SpawnZone
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| SDL_Rect | z | N/A |
| vector<EnemyType*> | e | N/A |

**Return Type:**  (N/A)


### SpawnZone::spawnEnemies
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| Player* | player | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** void (N/A)


## src/SpriteSheet.cpp
### SpriteSheet::SpriteSheet
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**  (N/A)


### SpriteSheet::SpriteSheet
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| SDL_Texture* | ptexture | N/A |
| int | x | N/A |
| int | y | N/A |
| int f) : | xFrames(x) | N/A |
|  | Frames(y) | N/A |
|  | rames(f | N/A |

**Return Type:**  (N/A)


## src/Stats.cpp
### Stats::Stats
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**  (N/A)


### Stats::Stats
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | s | N/A |
| int | v | N/A |
| int | m | N/A |
| int | a | N/A |
| int | l | N/A |
| int ap) : | st(s) | N/A |
|  | i(v) | N/A |
|  | a(m) | N/A |
|  | g(a) | N/A |
|  | u(l) | N/A |
|  | p_max(ap | N/A |

**Return Type:**  (N/A)


### Stats::giveEXP
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** int (N/A)


### Stats::getStatTotal
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** int (N/A)


### Stats::getLevel
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** int (N/A)


### Stats::resetStats
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** void (N/A)


### Stats::setStats
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| bool | override | N/A |

**Return Type:** void (N/A)


## src/TextBox.cpp
### TextBox::TextBox
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | N/A |
| vector<TextSlice> t) : | text(t | N/A |

**Return Type:**  (N/A)


### TextBox::draw
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | N/A |

**Return Type:** bool (N/A)


## src/TextObject.cpp
### TextObject::TextObject
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| int | n | N/A |
| Fightable* | gotHit | N/A |
| bool | crit | N/A |

**Return Type:**  (N/A)


### TextObject::TextObject
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| string | t | N/A |
| Fightable* | gotHit | N/A |
| SDL_Color c) : | text(t) | N/A |
|  | olor(c | N/A |

**Return Type:**  (N/A)


### TextObject::setText
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |

**Return Type:** void (N/A)


### TextObject::centerOn
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| Fightable* | gotHit | N/A |

**Return Type:** void (N/A)


### TextObject::draw
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| World* | world | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** bool (N/A)


## src/TextSequence.cpp
### TextSequence::TextSequence
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<TextBox> | t | N/A |
|  | ap<char | N/A |
| Mix_Chunk*>* s) : | text(t | N/A |

**Return Type:**  (N/A)


### TextSequence::draw
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | N/A |

**Return Type:** bool (N/A)


## src/TextSlice.cpp
### TextSlice::TextSlice
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | N/A |
| string t) : | text(t | N/A |

**Return Type:**  (N/A)


### TextSlice::TextSlice
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | N/A |
| string | t | N/A |
| SDL_Color c) : | text(t) | N/A |
|  | olor(c | N/A |

**Return Type:**  (N/A)


### TextSlice::TextSlice
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | N/A |
| string | t | N/A |
| SDL_Color | c | N/A |
| vector<TextEffect> e) : | text(t) | N/A |
|  | olor(c | N/A |

**Return Type:**  (N/A)


### TextSlice::draw
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | N/A |

**Return Type:** bool (N/A)


### TextSlice::setEffects
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<TextEffect> | e | N/A |

**Return Type:** void (N/A)


## src/TileLayer.cpp
### TileLayer::TileLayer
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| std::size_t | tileCount | N/A |

**Return Type:**  (N/A)


### m_tiles.reserve
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ileCount | N/A |

**Return Type:**     (N/A)


### TileLayer::parse
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |
|  | ap* | N/A |

**Return Type:** void (N/A)


### node.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     std::string attribName = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "node not a layer | node | N/A |
| skipped | parsing" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### setName
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("name").as_string() | N/A |

**Return Type:**     (N/A)


### setOpacity
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("opacity").as_float(1.f) | N/A |

**Return Type:**     (N/A)


### setVisible
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("visible").as_bool(true) | N/A |

**Return Type:**     (N/A)


### setOffset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("offsetx").as_int() | N/A |
|  | ode.attribute("offsety").as_int() | N/A |

**Return Type:**     (N/A)


### setSize
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode.attribute("width").as_uint() | N/A |
|  | ode.attribute("height").as_uint() | N/A |

**Return Type:**     (N/A)


### child.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         attribName = (N/A)


### child.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | encoding").as_string( | N/A |

**Return Type:**             attribName = (N/A)


### parseBase64
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | hild | N/A |

**Return Type:**                 (N/A)


### parseCSV
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | hild | N/A |

**Return Type:**                 (N/A)


### parseUnencoded
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | hild | N/A |

**Return Type:**                 (N/A)


### addProperty
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  |  | N/A |

**Return Type:**                 (N/A)


### TileLayer::parseBase64
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |

**Return Type:** void (N/A)


### []
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| std::string | dataString | N/A |
| std::size_t | tileCount | N/A |
| bool | compressed | N/A |

**Return Type:**     auto processDataString = (N/A)


### base64_decode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ataString | N/A |

**Return Type:**         dataString = (N/A)


### byteData.reserve
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | xpectedSize | N/A |

**Return Type:**         (N/A)


### dataString.length
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| ) * sizeof(unsigned | char | N/A |

**Return Type:**             std::size_t dataSize = (N/A)


### LOG
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Failed to decompress layer | data | N/A |
| node | skipped." | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**                 (N/A)


### byteData.insert
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | yteData.end() | N/A |
|  | ataString.begin() | N/A |
|  | ataString.end() | N/A |

**Return Type:**             (N/A)


### IDs.reserve
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ileCount | N/A |

**Return Type:**         (N/A)


### IDs.push_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | d | N/A |

**Return Type:**             (N/A)


### node.text
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | .as_string( | N/A |

**Return Type:**     std::string data = (N/A)


### childNode.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**             std::string childName = (N/A)


### childNode.text
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | .as_string( | N/A |

**Return Type:**                 std::string dataString = (N/A)


### childNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | x").as_int( | N/A |

**Return Type:**                     chunk.position.x = (N/A)


### childNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | y").as_int( | N/A |

**Return Type:**                     chunk.position.y = (N/A)


### childNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | width").as_int( | N/A |

**Return Type:**                     chunk.size.x = (N/A)


### childNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | height").as_int( | N/A |

**Return Type:**                     chunk.size.y = (N/A)


### processDataString
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ataString | N/A |
| (chunk.size.x * | chunk.size.y) | N/A |
|  | ode.attribute("compression") | N/A |

**Return Type:**                     auto IDs = (N/A)


### createTiles
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | Ds | N/A |
|  | hunk.tiles | N/A |

**Return Type:**                         (N/A)


### m_chunks.push_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | hunk | N/A |

**Return Type:**                         (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Layer " + getName() + " has no layer data. Layer | skipped." | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**             (N/A)


### processDataString
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ata | N/A |
|  | _tileCount | N/A |
|  | ode.attribute("compression") | N/A |

**Return Type:**         auto IDs = (N/A)


### createTiles
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | Ds | N/A |
|  | _tiles | N/A |

**Return Type:**         (N/A)


### TileLayer::parseCSV
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |

**Return Type:** void (N/A)


### []
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const std::string | dataString | N/A |
| std::size_t | tileCount | N/A |

**Return Type:**     auto processDataString = (N/A)


### IDs.reserve
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ileCount | N/A |

**Return Type:**         (N/A)


### dataString.c_str
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         const char* ptr = (N/A)


### std::strtoul
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | tr | N/A |
|  | end | N/A |
|  | 0 | N/A |

**Return Type:**             auto res = (N/A)


### IDs.push_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | es | N/A |

**Return Type:**             (N/A)


### node.text
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | .as_string( | N/A |

**Return Type:**     std::string data = (N/A)


### childNode.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**             std::string childName = (N/A)


### childNode.text
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | .as_string( | N/A |

**Return Type:**                 std::string dataString = (N/A)


### childNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | x").as_int( | N/A |

**Return Type:**                     chunk.position.x = (N/A)


### childNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | y").as_int( | N/A |

**Return Type:**                     chunk.position.y = (N/A)


### childNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | width").as_int( | N/A |

**Return Type:**                     chunk.size.x = (N/A)


### childNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | height").as_int( | N/A |

**Return Type:**                     chunk.size.y = (N/A)


### processDataString
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ataString | N/A |
| chunk.size.x * | chunk.size.y | N/A |

**Return Type:**                     auto IDs = (N/A)


### createTiles
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | Ds | N/A |
|  | hunk.tiles | N/A |

**Return Type:**                         (N/A)


### m_chunks.push_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | hunk | N/A |

**Return Type:**                         (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Layer " + getName() + " has no layer data. Layer | skipped." | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**             (N/A)


### createTiles
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | rocessDataString(data | N/A |
|  | _tileCount) | N/A |
|  | _tiles | N/A |

**Return Type:**         (N/A)


### TileLayer::parseUnencoded
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |

**Return Type:** void (N/A)


### IDs.reserve
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | _tileCount | N/A |

**Return Type:**     (N/A)


### child.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         attribName = (N/A)


### IDs.push_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | hild.attribute("gid").as_uint() | N/A |

**Return Type:**             (N/A)


### createTiles
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | Ds | N/A |
|  | _tiles | N/A |

**Return Type:**     (N/A)


### TileLayer::createTiles
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const std::vector<std::uint32_t>& | IDs | N/A |
| std::vector<Tile>& | destination | N/A |

**Return Type:** void (N/A)


### //LOG
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | Ds.size( | N/A |

**Return Type:**     (N/A)


### std::to_string
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| IDs.size()) + | " | N/A |
| expected: " + | std::to_string(m_tileCount) | N/A |

**Return Type:**     //    + (N/A)


### destination.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         (N/A)


### destination.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| ).flipFlags = ((id & mask) >> | 28 | N/A |

**Return Type:**         (N/A)


### destination.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         (N/A)


## src/Tileset.cpp
### Tileset::Tileset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const std::string& | workingDir | N/A |

**Return Type:**  (N/A)


### Tileset::parse
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| pugi::xml_node | node | N/A |
| Map* | map | N/A |

**Return Type:** void (N/A)


### assert
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ap | N/A |

**Return Type:**     (N/A)


### node.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     std::string attribString = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| attribString + ": not a tileset node! Node will be | skipped." | N/A |
|  | ogger::Type::Warning | N/A |

**Return Type:**         (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | firstgid").as_int( | N/A |

**Return Type:**     m_firstGID = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Invalid first GID in tileset. Tileset node | skipped." | N/A |
|  | ogger::Type::Warning | N/A |

**Return Type:**         (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | source").as_string( | N/A |

**Return Type:**         std::string path = (N/A)


### resolveFilePath
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ath | N/A |
|  | _workingDir | N/A |

**Return Type:**         path = (N/A)


### path.find_last_of
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | /' | N/A |

**Return Type:**         auto position = (N/A)


### path.substr
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  |  | N/A |
|  | osition | N/A |

**Return Type:**             m_workingDir = (N/A)


### tsxDoc.load_file
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ath.c_str() | N/A |

**Return Type:**         auto result = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Failed opening tsx file for tile | set | N/A |
| tile set will be | skipped" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**             (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**             return (N/A)


### tsxDoc.child
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | tileset" | N/A |

**Return Type:**         node = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "tsx file does not contain a tile set | node | N/A |
| tile set will be | skipped" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**             (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**             return (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | name").as_string( | N/A |

**Return Type:**     m_name = (N/A)


### LOG
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "found tile set " + | m_name | N/A |
|  | ogger::Type::Info | N/A |

**Return Type:**     (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | tilewidth").as_int( | N/A |

**Return Type:**     m_tileSize.x = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | tileheight").as_int( | N/A |

**Return Type:**     m_tileSize.y = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Invalid tile size found in tile set node. Node will be | skipped." | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**         (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         return (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | spacing").as_int( | N/A |

**Return Type:**     m_spacing = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | margin").as_int( | N/A |

**Return Type:**     m_margin = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | tilecount").as_int( | N/A |

**Return Type:**     m_tileCount = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | columns").as_int( | N/A |

**Return Type:**     m_columnCount = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | objectalignment").as_string( | N/A |

**Return Type:**     std::string objectAlignment = (N/A)


### node.children
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     const auto& children = (N/A)


### node.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         std::string name = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | source").as_string( | N/A |

**Return Type:**             attribString = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Tileset image node has missing source | property | N/A |
| tile set not | loaded" | N/A |
|  | ogger::Type::Error | N/A |

**Return Type:**                 (N/A)


### reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**                 return (N/A)


### resolveFilePath
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ttribString | N/A |
|  | _workingDir | N/A |

**Return Type:**             m_imagePath = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | trans").as_string( | N/A |

**Return Type:**                 attribString = (N/A)


### colourFromString
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ttribString | N/A |

**Return Type:**                 m_transparencyColour = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | width").as_int( | N/A |

**Return Type:**                 m_imageSize.x = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | height").as_int( | N/A |

**Return Type:**                 m_imageSize.y = (N/A)


### parseOffsetNode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode | N/A |

**Return Type:**             (N/A)


### parsePropertyNode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode | N/A |

**Return Type:**             (N/A)


### parseTerrainNode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode | N/A |

**Return Type:**             (N/A)


### parseTileNode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ode | N/A |
|  | ap | N/A |

**Return Type:**             (N/A)


### createMissingTile
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | D | N/A |

**Return Type:**             (N/A)


### std::sort
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | _tiles.begin() | N/A |
|  | _tiles.end() | N/A |
| [](const Tile& | t1 | N/A |
| const Tile& t2) {return t1.ID < t2.ID; | } | N/A |

**Return Type:**     (N/A)


### Tileset::getLastGID
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** std::uint32_t (N/A)


### assert
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | m_tiles.empty() | N/A |

**Return Type:**     (N/A)


### m_tiles.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     return m_firstGID + (N/A)


### Tileset::getTile
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| std::uint32_t | id | N/A |

**Return Type:** const Tileset::Tile* (N/A)


### std::find_if
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | _tiles.begin() | N/A |
|  | _tiles.end( | N/A |

**Return Type:**     const auto itr = (N/A)


### [id]
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const Tile& | tile | N/A |

**Return Type:**         (N/A)


### Tileset::reset
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** void (N/A)


### m_properties.clear
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     (N/A)


### m_terrainTypes.clear
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     (N/A)


### m_tiles.clear
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     (N/A)


### Tileset::parseOffsetNode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |

**Return Type:** void (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | x").as_int( | N/A |

**Return Type:**     m_tileOffset.x = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | y").as_int( | N/A |

**Return Type:**     m_tileOffset.y = (N/A)


### Tileset::parsePropertyNode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |

**Return Type:** void (N/A)


### node.children
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     const auto& children = (N/A)


### m_properties.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         (N/A)


### m_properties.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | .parse(child | N/A |

**Return Type:**         (N/A)


### Tileset::parseTerrainNode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |

**Return Type:** void (N/A)


### node.children
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     const auto& children = (N/A)


### child.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         std::string name = (N/A)


### m_terrainTypes.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**             (N/A)


### m_terrainTypes.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**             auto& terrain = (N/A)


### child.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | name").as_string( | N/A |

**Return Type:**             terrain.name = (N/A)


### child.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | tile").as_int( | N/A |

**Return Type:**             terrain.tileID = (N/A)


### child.child
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | properties" | N/A |

**Return Type:**             auto properties = (N/A)


### p.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**                     name = (N/A)


### terrain.properties.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**                         (N/A)


### terrain.properties.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | .parse(p | N/A |

**Return Type:**                         (N/A)


### Tileset::parseTileNode
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| const pugi::xml_node& | node | N/A |
| Map* | map | N/A |

**Return Type:** void (N/A)


### assert
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ap | N/A |

**Return Type:**     (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | id").as_int( | N/A |

**Return Type:**     tile.ID = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | terrain").as_string( | N/A |

**Return Type:**         std::string data = (N/A)


### std::atoi
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | data[i] | N/A |

**Return Type:**                 tile.terrainIndices[idx++] = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | probability").as_int(100 | N/A |

**Return Type:**     tile.probability = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | type").as_string( | N/A |

**Return Type:**     tile.Class = (N/A)


### node.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | class").as_string( | N/A |

**Return Type:**         tile.Class = (N/A)


### node.children
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**     const auto& children = (N/A)


### child.name
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**         std::string name = (N/A)


### tile.properties.emplace_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:**                 (N/A)


### tile.properties.back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | .parse(prop | N/A |

**Return Type:**                 (N/A)


### tile.objectGroup.parse
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | hild | N/A |
|  | ap | N/A |

**Return Type:**             (N/A)


### child.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | source").as_string( | N/A |

**Return Type:**             std::string attribString = (N/A)


### Logger::log
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| "Tile image path | missing" | N/A |
|  | ogger::Type::Warning | N/A |

**Return Type:**                 (N/A)


### resolveFilePath
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ttribString | N/A |
|  | _workingDir | N/A |

**Return Type:**             tile.imagePath = (N/A)


### tmx::Vector2u
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  |  | N/A |
|  |  | N/A |

**Return Type:**             tile.imagePosition = (N/A)


### child.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | trans").as_string( | N/A |

**Return Type:**                 attribString = (N/A)


### colourFromString
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ttribString | N/A |

**Return Type:**                 m_transparencyColour = (N/A)


### child.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | width").as_uint( | N/A |

**Return Type:**                 tile.imageSize.x = (N/A)


### child.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | height").as_uint( | N/A |

**Return Type:**                 tile.imageSize.y = (N/A)


### frameNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | duration").as_int( | N/A |

**Return Type:**                 frame.duration = (N/A)


### frameNode.attribute
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | tileid").as_int( | N/A |

**Return Type:**                 frame.tileID = (N/A)


### tile.animation.frames.push_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | rame | N/A |

**Return Type:**                 (N/A)


### m_tiles.push_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ile | N/A |

**Return Type:**     (N/A)


### Tileset::createMissingTile
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| std::uint32_t | ID | N/A |

**Return Type:** void (N/A)


### m_tiles.push_back
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
|  | ile | N/A |

**Return Type:**     (N/A)


## src/utils.cpp
### random
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 

**Return Type:** float ( A random float from 0.0 to 1.0)


### rand
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| float | std | The standard deviation for the bell curve |
| float | m | The mean of the bell curve |

**Return Type:** float ( A random number with mean m and standard deviation of std)


### invNorm
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| float | x | cdf of a standard normal distribution |

**Return Type:** float ( The z-value of x )


### RationalApproximation
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| float | t | N/A |

**Return Type:** float (N/A)


### weighted
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<Fightable*> | party | N/A |

**Return Type:** float (N/A)


### weighted
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<Enemy*> | party | N/A |

**Return Type:** float (N/A)


### average
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<Fightable*> | party | N/A |

**Return Type:** float (N/A)


### diffSum
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| int | a | N/A |
| int | b | N/A |

**Return Type:** int (N/A)


### quadratic
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| float | a | N/A |
| float | b | N/A |
| float | c | N/A |

**Return Type:** float (N/A)


### increase
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| float | initial | N/A |
| float | percent | N/A |

**Return Type:** float (N/A)


### distanceFrom
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| float | x | N/A |
| float | y | N/A |

**Return Type:** float (N/A)


### angleFromCoords
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| float | x | N/A |
| float | y | N/A |

**Return Type:** float (N/A)


### angleFromCoords
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| float | x | N/A |
| float | y | N/A |
| float | (\*foo)(vector<void*>) | N/A |
| vector<void*> | bonus | N/A |

**Return Type:** float (N/A)


### literalAtan
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | vv | N/A |

**Return Type:** float (N/A)


### atanApprox
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| vector<void*> | vv | N/A |

**Return Type:** float (N/A)


### arrowChange
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow* | window | N/A |
| vector<SDL_Scancode>& | keys | N/A |
| bool* | direction | N/A |
| void | (\*foo)(vector<void*>) | N/A |
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


## src/World.cpp
### World::World
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| RenderWindow& | window | N/A |
| Player* | player | N/A |
| vector<EnemyType*> | enemyTypes | N/A |

**Return Type:**  (N/A)


### World::switchArea
| **Type** | **Variable Name** | **Description** | 
| -------- | ----------------- | --------------- | 
| string | s | N/A |
| Player* | player | N/A |

**Return Type:** void (N/A)


