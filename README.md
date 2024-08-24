# Project Documentation

## src/Area.cpp
### getTilesetCoords
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| int | columns | N/A |
| int | id | N/A |

**Return Type:** Vector2u (N/A)


### angleBetween
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Vector2f | vec1 | N/A |
| Vector2f | vec2 | N/A |

**Return Type:** float (N/A)


### magnitude
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Vector2f | vec | N/A |

**Return Type:** float (N/A)


### dotProduct
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Vector2f | vec1 | N/A |
| Vector2f | vec2 | N/A |

**Return Type:** float (N/A)


### vectorFromAngle
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| float | angle | N/A |

**Return Type:** Vector2f (N/A)


### getMinMax
*Gets the minimum and maximum dot products of vec to every point in points*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Vector2f | vec | A vector that you are finding the min/max of |
| const vector<Vector2f>& | points | The points that we are getting the dot products of |

**Return Type:** MinMax (A datatype that holds the min and max dotproducts)


### addUnique
*Modifies anglesToCheck to add the angle associated with vec IF the angle doesnt already exist in anglesToCheck*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Vector2f | vec | The vector we might add to anglesToCheck |
| vector<float>& | anglesToCheck | N/A |

**Return Type:** void (N/A)


### Area::Area
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | N/A |
| string | path | N/A |
| vector<EnemyType*> | enemyTypes | N/A |
| string | bg | N/A |
|  | ap<string | N/A |
|  | ap<char | N/A |
| Mix_Chunk*>>& | textNoise | N/A |

**Return Type:**  (N/A)


### Area::diagonalTileFinder
*Tiles in Tiled can be diagonally flipped, which cannot be done with simple flips and rotations. This function finds which tiles get diagonally flipped and creates a new texutre that is the diagonally flipped version of it.*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | A renderwindow is used to create the diagonally flipped textures |
| const Layer::Ptr& | layer | The layer with tiles |

**Return Type:** void (N/A)


### Area::getIndexForID
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| int& | ID | N/A |

**Return Type:** int (N/A)


### Area::renderLayer
*Tiled tmxmaps have layers, this function renders a layer. *
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | N/A |
| const Layer::Ptr& | layer | N/A |
| IntRect | intrect | N/A |

**Return Type:** void (N/A)


### Area::subRender
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| const Layer::Ptr& | layer | N/A |
| RenderWindow& | window | N/A |
| IntRect | rect | N/A |

**Return Type:** void (N/A)


### Area::render
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | N/A |
| Player* | player | N/A |
| World* | world | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** void (N/A)


### Area::placePlayer
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Player* | player | N/A |

**Return Type:** void (N/A)


### Area::collision
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | N/A |
| Collideable* | player | N/A |

**Return Type:** void (N/A)


## src/BattleOptions.cpp
### BattleOptions::BattleOptions
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | N/A |

**Return Type:**  (N/A)


### BattleOptions::makeMaxWidth
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Entity*& | object | N/A |
| double& | scalingSize | N/A |
| SDL_Texture* | texture | N/A |

**Return Type:** void (N/A)


### BattleOptions::customDraw
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |

**Return Type:** void (N/A)


### BattleOptions::selectionLimiting
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** void (N/A)


### boDecrement
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### boIncrement
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### boUp
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### boDown
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### boSelect
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### boMainOptionSelect
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


## src/Buff.cpp
### Buff::Buff
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| int | l | N/A |
| int | t | N/A |
| BuffType | b | N/A |

**Return Type:**  (N/A)


### Buff::Buff
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| const Buff | &t | N/A |

**Return Type:**  (N/A)


### Buff::infoUpdate
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** void (N/A)


### Buff::changeBuff
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Buff | b | N/A |
| double | (\*op)(double | N/A |
|  | ouble) | N/A |

**Return Type:** void (N/A)


### Add
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| double | a | N/A |
| double | b | N/A |

**Return Type:** double (N/A)


### Subtract
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| double | a | N/A |
| double | b | N/A |

**Return Type:** double (N/A)


### Buff::merge
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Buff | b | N/A |

**Return Type:** void (N/A)


### Buff::remove
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Buff | b | N/A |

**Return Type:** void (N/A)


### Buff::effect
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Fightable | character | N/A |

**Return Type:** void (N/A)


### Buff::turnOver
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Fightable | f | N/A |

**Return Type:** void (N/A)


## src/BuffMove.cpp
### BuffMove::BuffMove
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
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
| int | h | N/A |

**Return Type:**  (N/A)


## src/BuffType.cpp
### BuffType::BuffType
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| string | n | N/A |
| string | d | N/A |
| bool | b | N/A |

**Return Type:**  (N/A)


### BuffType::effect
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| int | level | N/A |
| Fightable | c | N/A |

**Return Type:** void (N/A)


### BuffType::operator==
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| BuffType& | bt | N/A |

**Return Type:** bool (N/A)


## src/Collideable.cpp
### Collideable::draw
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| World* | world | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** bool (N/A)


### Collideable::getHitbox
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** SDL_Rect (N/A)


### Collideable::getPoints
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** vector<Vector2f> (N/A)


## src/ControlsConfig.cpp
## src/Enemy.cpp
### Enemy::Enemy
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| EnemyType* | e | N/A |
| int | x | N/A |
| int | y | N/A |
| Player* | p | N/A |

**Return Type:**  (N/A)


### Enemy::draw
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| World* | world | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** bool (N/A)


### Enemy::changeSpriteSheet
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| string | newSheet | N/A |

**Return Type:** void (N/A)


### Enemy::battle
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| Fightable* | turn | N/A |
| vector<GameObject*>& | battleEntities | N/A |

**Return Type:** void (N/A)


## src/EnemyType.cpp
### EnemyType::EnemyType
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
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
| :------: | :---------------: | :-------------: | 

**Return Type:**  (N/A)


### Entity::Entity
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:**  (N/A)


### Entity::Entity
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| float | px | N/A |
| float | py | N/A |
| SDL_Texture* | ptexture | N/A |
| int | pw | N/A |
| int | ph | N/A |

**Return Type:**  (N/A)


### Entity::Entity
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| float | px | N/A |
| float | py | N/A |
| SDL_Texture* | ptexture | N/A |

**Return Type:**  (N/A)


### Entity::setTexture
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| SDL_Texture* | ptexture | N/A |

**Return Type:** void (N/A)


### Entity::Entity
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| const Entity& | e | N/A |

**Return Type:**  (N/A)


### Entity::fullPicSize
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** void (N/A)


### Entity::setRect
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** void (N/A)


### Entity::getsize
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** SDL_Point (N/A)


### SDL_QueryTexture
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
|  | exture.get() | N/A |
|  | ULL | N/A |
|  | ULL | N/A |
|  | size.x | N/A |
|  | size.y | N/A |

**Return Type:**     (N/A)


### Entity::getRect
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** SDL_Rect (N/A)


### Entity::distance
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Entity* | e | N/A |

**Return Type:** float (N/A)


### Entity::angleBetween
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Entity* | e | N/A |

**Return Type:** float (N/A)


### Entity::customDraw
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |

**Return Type:** void (N/A)


## src/Fightable.cpp
### Fightable::Fightable
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:**  (N/A)


### Fightable::battle
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| Fightable* | turn | N/A |
| vector<GameObject*>& | battleEntities | N/A |

**Return Type:** void (N/A)


### Fightable::battleInit
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | N/A |
| int | index | N/A |

**Return Type:** void (N/A)


### Fightable::addToExhaustQueue
*Adds a move to the exhaust queue*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Move* | move | The move that is being added to the exhaust queue |

**Return Type:** void (N/A)


### Fightable::getExhaust
*Gets the moves exhaust multiplier via the staling queue*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Move* | move | The move that is being checked for its exhaust |

**Return Type:** float (The exhaust multiplier to the move)


## src/FreeFuncs.cpp
## src/GameObject.cpp
### GameObject::GameObject
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:**  (N/A)


### GameObject::GameObject
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| float | px | N/A |
| float | py | N/A |
| SDL_Texture* | ptexture | N/A |
| int | pw | N/A |
| int | ph | N/A |

**Return Type:**  (N/A)


### GameObject::draw
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| World* | world | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** bool (N/A)


### GameObject::changeSpriteSheet
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| string | newSheet | N/A |

**Return Type:** void (N/A)


### GameObject::createObject
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** GameObject* (N/A)


## src/HealthBar.cpp
### HealthBar::HealthBar
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| int | x | N/A |
| int | y | N/A |
| int | w | N/A |
| int | h | N/A |

**Return Type:**  (N/A)


### HealthBar::~HealthBar
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:**  (N/A)


### HealthBar::represent
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| Fightable* | fighter | N/A |

**Return Type:** void (N/A)


## src/ImageLayer.cpp
## src/Interactable.cpp
### Interactable::Interactable
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| SDL_Rect | r | N/A |
| TextSequence* | i | N/A |

**Return Type:**  (N/A)


### Interactable::~Interactable
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:**  (N/A)


## src/KeyFrame.cpp
### KeyFrame::KeyFrame
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| int | f | N/A |
| string | a | N/A |
| int | ro | N/A |
| int | xTemp | N/A |
| int | yTemp | N/A |
| ReferenceFrame | r | N/A |
| Interpolation | i | N/A |
| bool | d | N/A |
| int | fd | N/A |

**Return Type:**  (N/A)


### KeyFrame::applyKeyframe
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Fightable* | attacker | N/A |
| KeyFrame& | previous | N/A |
| int | curFrame | N/A |
| Fightable* | defender | N/A |
| bool | reverse | N/A |

**Return Type:** void (N/A)


### KeyFrame::base
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Fightable* | attacker | N/A |
| Fightable* | defender | N/A |
| bool | reverse | N/A |

**Return Type:** pair<int, int> (N/A)


## src/LayerGroup.cpp
## src/main.cpp
### atanLookup
*Unused function that executes an Inverse Tangent via table lookup using binary search. The table used to be stored in RenderWindow*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | vv | Vector of RenderWindow in index 0 and float that you are looking for in index 1 |

**Return Type:** float (s atan of vv[1])


### flippedIndex
*I dont remember what this does, its something for spiral / darkness though*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| int | num | N/A |
|  | ector<pair<int | N/A |
| int>>& | degree45 | N/A |
| int subtract = | 0 | N/A |

**Return Type:** inline pair<int, int> (N/A)


### inRange
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| int | n | N/A |
| int | s | N/A |
| int | l | N/A |

**Return Type:** inline bool (N/A)


### operator+
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| const | pair<int | N/A |
| int>& | a | N/A |
| const | pair<int | N/A |
| int>& | b | N/A |

**Return Type:** pair<int, int> (N/A)


### operator<<
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| ostream& | os | N/A |
| const KeyFrame& | obj | N/A |

**Return Type:** ostream& (N/A)


### spiralPerPixel
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
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
| :------: | :---------------: | :-------------: | 
| int | transitionFrames | N/A |
|  | ector<pair<int | N/A |
| int>>& | degree45 | N/A |
| int | r | N/A |
| SDL_Rect& | texture_rect | N/A |

**Return Type:** double (N/A)


### blackCompute
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| int | transitionFrames | N/A |
|  | ector<pair<int | N/A |
| int>>& | degree45 | N/A |
| int | r | N/A |
| SDL_Rect& | texture_rect | N/A |

**Return Type:** double (N/A)


### blackPerPixel
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
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
| :------: | :---------------: | :-------------: | 
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
| :------: | :---------------: | :-------------: | 
| string | s | N/A |

**Return Type:** map<char, Mix_Chunk*> (N/A)


### backout
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### forward
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### sortComb
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<T*>& | vec | N/A |
| int | (\*foo)(T*) | N/A |

**Return Type:** void (N/A)


### getValue
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Fightable* | f | N/A |

**Return Type:** int (N/A)


### getValue
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Enemy* | f | N/A |

**Return Type:** int (N/A)


### rhythmPress
*Is called whenever a key is pressed during the rhythm section*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<RhythmNote*>* | notes | The notes that need to be pressed during the rhythm game section |
| float* | howGoodYouDoIt | A pointer to a variable that will be used to calculate damage and other things |
| float | maxGoodness | The maximum amount that can be added to howGoodYouDoIt per note |
| NoteType | nt | The note type / key that the player is pressing |

**Return Type:** void (N/A)


### rhythmPressUp
*Deals with up presses by calling the general rhythmPress. This is done as this function is passed as a function pointer for arrow presses.*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | Contains, in this order, the notes, a pointer to howGoodYouDoIt and maxGoodness |

**Return Type:** void (N/A)


### rhythmPressLeft
*Deals with left presses by calling the general rhythmPress. This is done as this function is passed as a function pointer for arrow presses.*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | Contains, in this order, the notes, a pointer to howGoodYouDoIt and maxGoodness |

**Return Type:** void (N/A)


### rhythmPressRight
*Deals with right presses by calling the general rhythmPress. This is done as this function is passed as a function pointer for arrow presses.*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | Contains, in this order, the notes, a pointer to howGoodYouDoIt and maxGoodness |

**Return Type:** void (N/A)


### rhythmPressDown
*Deals with down presses by calling the general rhythmPress. This is done as this function is passed as a function pointer for arrow presses.*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | Contains, in this order, the notes, a pointer to howGoodYouDoIt and maxGoodness |

**Return Type:** void (N/A)


### threadCircularApplication
*This whole thing does full screen visual effects such as darkening edges and spiralling pixels*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
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
| :------: | :---------------: | :-------------: | 
| int | argc | N/A |
| char | *argv[] | N/A |

**Return Type:** int (N/A)


## src/Map.cpp
## src/Move.cpp
### Move::Move
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
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
| int | h | N/A |

**Return Type:**  (N/A)


### Move::getHitting
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Fightable* | attacker | N/A |
| Fightable* | defender | N/A |

**Return Type:** bool (N/A)


### Move::getCrit
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Fightable* | attacker | N/A |

**Return Type:** bool (N/A)


### Move::dealDamage
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| Fightable* | attacker | N/A |
| Fightable* | defender | N/A |
| vector<GameObject*>& | battleEntities | N/A |
| bool | hitting | N/A |
| bool | crit | N/A |
| float | howGoodYouDoIt | N/A |

**Return Type:** void (N/A)


## src/Object.cpp
## src/ObjectGroup.cpp
## src/ObjectTypes.cpp
## src/PartyMember.cpp
### PartyMember::battle
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| Fightable* | turn | N/A |
| vector<GameObject*>& | battleEntities | N/A |

**Return Type:** void (N/A)


### PartyMember::doAttack
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| Fightable* | enemy | N/A |
| vector<GameObject*>& | battleEntities | N/A |

**Return Type:** void (N/A)


## src/Player.cpp
### InputLinkedList::InputLinkedList
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| int | i | N/A |

**Return Type:**  (N/A)


### InputLinkedList::~InputLinkedList
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:**  (N/A)


### pushBack
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| InputLinkedList* | ill | N/A |
| int | i | N/A |

**Return Type:** InputLinkedList* (N/A)


### find
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| InputLinkedList* | ill | N/A |
| int | i | N/A |

**Return Type:** InputLinkedList* (N/A)


### pullForward
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| InputLinkedList* | ill | N/A |
| int | i | N/A |

**Return Type:** InputLinkedList* (N/A)


### addInput
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| InputLinkedList* | ill | N/A |
| int | i | N/A |

**Return Type:** InputLinkedList* (N/A)


### Player::Player
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| vector<Move*> | m | N/A |

**Return Type:**  (N/A)


### interactCheck
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | vv | N/A |

**Return Type:** void (N/A)


### Player::draw
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| World* | world | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** bool (N/A)


### Player::changeDirection
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** void (N/A)


## src/Property.cpp
## src/RenderWindow.cpp
### RenderWindow::RenderWindow
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| const char* | title | N/A |

**Return Type:**  (N/A)


### RenderWindow::resizeWindow
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** void (N/A)


### RenderWindow::cleanUp
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** void (N/A)


### RenderWindow::loadTexture
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| const char* | filePath | N/A |

**Return Type:** SDL_Texture* (N/A)


### RenderWindow::clear
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** void (N/A)


### RenderWindow::setColor
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| int | r | N/A |
| int | g | N/A |
| int | b | N/A |
| int | a | N/A |

**Return Type:** void (N/A)


### RenderWindow::drawLine
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| int | x1 | N/A |
| int | y1 | N/A |
| int | x2 | N/A |
| int | y2 | N/A |
| bool | stationary | N/A |

**Return Type:** void (N/A)


### RenderWindow::getDestRect
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Entity* | entity | N/A |
| bool | stationary | N/A |

**Return Type:** SDL_Rect (N/A)


### RenderWindow::scaleDestRect
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| SDL_Rect& | dest | N/A |

**Return Type:** void (N/A)


### RenderWindow::render
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Entity* | entity | N/A |
| bool | stationary | N/A |
| int | centerx | N/A |
| int | centery | N/A |

**Return Type:** void (N/A)


### RenderWindow::display
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** void (N/A)


### RenderWindow::drawCircle
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| int | x | N/A |
| int | y | N/A |
| int | radius | N/A |

**Return Type:** void (N/A)


### RenderWindow::getTextSurface
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| string | text | N/A |
| unsigned char | r | N/A |
| unsigned char | g | N/A |
| unsigned char | b | N/A |
| unsigned char | a | N/A |

**Return Type:** SDL_Surface* (N/A)


### SDL_GetError
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** //	cout << (N/A)


### TTF_GetError
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** //	cout << (N/A)


### RenderWindow::drawScaledTextInBox
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
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
| :------: | :---------------: | :-------------: | 
| SDL_Surface* | surfaceMessage | N/A |
| SDL_Texture* | Message | N/A |
| SDL_Rect | Message_rect | N/A |

**Return Type:** void (N/A)


### RenderWindow::drawText
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
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
| :------: | :---------------: | :-------------: | 
| SDL_Rect& | rect | N/A |
| SDL_Texture* | source | N/A |

**Return Type:** SDL_Texture* (N/A)


## src/RhythmNote.cpp
### RhythmNote::RhythmNote
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
|  | air<int | N/A |
| NoteType> | note | N/A |
| chrono::steady_clock::time_point* | s | N/A |

**Return Type:**  (N/A)


### RhythmNote::draw
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| World* | world | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** bool (N/A)


## src/Selector.cpp
### Selector::Selector
*Creates a Selector*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | Window used to load the selector texture |

**Return Type:**  (Selector)


### Selector::render
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** void (N/A)


### Selector::getSelected
*Gets the selected enemy the cursor is hovering over*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | Window used to get the teams |

**Return Type:** Fightable* (Fighter that is selected)


### sDecrement
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### sIncrement
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### sEnter
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### sParty
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### sEnemy
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


## src/SpawnZone.cpp
### SpawnZone::SpawnZone
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| SDL_Rect | z | N/A |
| vector<EnemyType*> | e | N/A |

**Return Type:**  (N/A)


### SpawnZone::spawnEnemies
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| Player* | player | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** void (N/A)


## src/SpriteSheet.cpp
### SpriteSheet::SpriteSheet
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:**  (N/A)


### SpriteSheet::SpriteSheet
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| SDL_Texture* | ptexture | N/A |
| int | x | N/A |
| int | y | N/A |
| int | f | N/A |

**Return Type:**  (N/A)


## src/Stats.cpp
### Stats::Stats
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:**  (N/A)


### Stats::Stats
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| int | s | N/A |
| int | v | N/A |
| int | m | N/A |
| int | a | N/A |
| int | l | N/A |
| int | ap | N/A |

**Return Type:**  (N/A)


### Stats::giveEXP
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** int (N/A)


### Stats::getStatTotal
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** int (N/A)


### Stats::getLevel
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** int (N/A)


### Stats::resetStats
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** void (N/A)


### Stats::setStats
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| bool | override | N/A |

**Return Type:** void (N/A)


## src/TextBox.cpp
### TextBox::TextBox
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | N/A |
| vector<TextSlice> | t | N/A |

**Return Type:**  (N/A)


### TextBox::reset
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** void (N/A)


### TextBox::draw
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | N/A |

**Return Type:** bool (N/A)


## src/TextObject.cpp
### TextObject::TextObject
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| int | n | N/A |
| Fightable* | gotHit | N/A |
| bool | crit | N/A |

**Return Type:**  (N/A)


### TextObject::TextObject
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| string | t | N/A |
| Fightable* | gotHit | N/A |
| SDL_Color | c | N/A |

**Return Type:**  (N/A)


### TextObject::setText
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |

**Return Type:** void (N/A)


### TextObject::centerOn
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| Fightable* | gotHit | N/A |

**Return Type:** void (N/A)


### TextObject::draw
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| World* | world | N/A |
| vector<GameObject*>& | entities | N/A |

**Return Type:** bool (N/A)


## src/TextSequence.cpp
### TextSequence::TextSequence
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<TextBox> | t | N/A |
|  | ap<char | N/A |
| Mix_Chunk*>* | s | N/A |

**Return Type:**  (N/A)


### TextSequence::draw
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | N/A |

**Return Type:** bool (N/A)


### TextSequence::reset
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** void (N/A)


## src/TextSlice.cpp
### TextSlice::TextSlice
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | N/A |
| string | t | N/A |

**Return Type:**  (N/A)


### TextSlice::TextSlice
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | N/A |
| string | t | N/A |
| SDL_Color | c | N/A |

**Return Type:**  (N/A)


### TextSlice::TextSlice
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | N/A |
| string | t | N/A |
| SDL_Color | c | N/A |
| vector<TextEffect> | e | N/A |

**Return Type:**  (N/A)


### TextSlice::draw
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | N/A |

**Return Type:** bool (N/A)


### TextSlice::setEffects
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<TextEffect> | e | N/A |

**Return Type:** void (N/A)


## src/TileLayer.cpp
## src/Tileset.cpp
## src/utils.cpp
### random
*The random function that is called in the entire code*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 

**Return Type:** float (A random float from 0.0 to 1.0)


### rand
*Gives a random number that follows a bell curve*
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| float | std | The standard deviation for the bell curve |
| float | m | The mean of the bell curve |

**Return Type:** float (A random number with mean m and standard deviation of std)


### invNorm
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| float | x | cdf of a standard normal distribution |

**Return Type:** float (The z-value of x )


### RationalApproximation
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| float | t | N/A |

**Return Type:** float (N/A)


### weighted
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<Fightable*> | party | N/A |

**Return Type:** float (N/A)


### weighted
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<Enemy*> | party | N/A |

**Return Type:** float (N/A)


### average
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<Fightable*> | party | N/A |

**Return Type:** float (N/A)


### diffSum
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| int | a | N/A |
| int | b | N/A |

**Return Type:** int (N/A)


### quadratic
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| float | a | N/A |
| float | b | N/A |
| float | c | N/A |

**Return Type:** float (N/A)


### increase
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| float | initial | N/A |
| float | percent | N/A |

**Return Type:** float (N/A)


### distanceFrom
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| float | x | N/A |
| float | y | N/A |

**Return Type:** float (N/A)


### angleFromCoords
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| float | x | N/A |
| float | y | N/A |

**Return Type:** float (N/A)


### angleFromCoords
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| float | x | N/A |
| float | y | N/A |
| float | (\*foo)(vector<void*>) | N/A |
| vector<void*> | bonus | N/A |

**Return Type:** float (N/A)


### literalAtan
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | vv | N/A |

**Return Type:** float (N/A)


### atanApprox
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| vector<void*> | vv | N/A |

**Return Type:** float (N/A)


### arrowChange
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow* | window | N/A |
| vector<SDL_Scancode>& | keys | N/A |
| bool* | direction | N/A |
| void | (\*foo)(vector<void*>) | N/A |
| vector<void*> | passingArgument | N/A |

**Return Type:** void (N/A)


### angleDiff
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| float | angle1 | N/A |
| float | angle2 | N/A |

**Return Type:** float (N/A)


## src/World.cpp
### World::World
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| RenderWindow& | window | N/A |
| Player* | player | N/A |
| vector<EnemyType*> | enemyTypes | N/A |
|  | ap<string | N/A |
|  | ap<char | N/A |
| Mix_Chunk*>>& | textNoise | N/A |

**Return Type:**  (N/A)


### World::switchArea
| **Type** | **Variable Name** | **Description** | 
| :------: | :---------------: | :-------------: | 
| string | s | N/A |
| Player* | player | N/A |

**Return Type:** void (N/A)


